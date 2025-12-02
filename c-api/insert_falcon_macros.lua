local ts = vim.treesitter

local function get_macro_end(ret_type)
	if ret_type:match("Handle$") then
		return "nullptr"
	elseif ret_type == "bool" then
		return "false"
	elseif ret_type == "int" or ret_type == "size_t" or ret_type == "std::size_t" then
		return "0"
	elseif ret_type == "float" or ret_type == "double" then
		return "0.0"
	else
		return ""
	end
end

local function ensure_error_include()
	local lines = vim.api.nvim_buf_get_lines(0, 0, -1, false)
	for _, line in ipairs(lines) do
		if line:find("ErrorHandling_c_api.h") then
			return
		end
	end
	local last_include = 0
	for i, line in ipairs(lines) do
		if line:match("^#include") then
			last_include = i
		end
	end
	vim.api.nvim_buf_set_lines(
		0,
		last_include,
		last_include,
		false,
		{ '#include "falcon_core/generic/ErrorHandling_c_api.h"' }
	)
end

local function insert_falcon_macros_and_extern_c()
	ensure_error_include()
	local bufnr = vim.api.nvim_get_current_buf()
	local parser = vim.treesitter.get_parser(bufnr)
	if not parser then
		print("No Treesitter parser for this buffer")
		return
	end
	local lang = parser:lang()
	local trees = parser:parse()
	if not trees or not trees[1] then
		print("No parse tree found")
		return
	end
	local tree = trees[1]
	local root = tree:root()
	if not root then
		print("No root node found")
		return
	end

	local func_query = ts.query.parse(
		lang,
		[[
    (function_definition
      type: (_) @ret_type
      declarator: (function_declarator
        declarator: (identifier) @func_name)
      body: (compound_statement) @body) @funcdef
    ]]
	)

	-- First pass: rewrite all single-line functions as multi-line with macros
	local single_line_funcs = {}
	for id, node, _ in func_query:iter_captures(root, bufnr, 0, -1) do
		local name = func_query.captures[id]
		if name == "body" then
			local body_node = node
			local start_row, _, end_row, _ = body_node:range()
			local parent = body_node:parent()
			local ret_type = ""
			for cid, cnode in func_query:iter_captures(parent, bufnr, 0, -1) do
				if func_query.captures[cid] == "ret_type" then
					ret_type = ts.get_node_text(cnode, bufnr)
				end
			end
			local macro_end = get_macro_end(ret_type)
			if start_row == end_row then
				table.insert(single_line_funcs, { start_row = start_row, macro_end = macro_end })
			end
		end
	end

	-- Rewrite single-line functions (from bottom to top to avoid shifting)
	table.sort(single_line_funcs, function(a, b)
		return a.start_row > b.start_row
	end)
	for _, func in ipairs(single_line_funcs) do
		local lines = vim.api.nvim_buf_get_lines(0, func.start_row, func.start_row + 1, false)
		local line = lines[1]
		local sig, body = line:match("^(.*{)(.*)}%s*$")
		if sig and body then
			local new_func = {
				sig,
				"  FALCON_C_API_BEGIN",
				"  " .. vim.trim(body),
				func.macro_end ~= "" and ("  FALCON_C_API_END(" .. func.macro_end .. ")") or "  FALCON_C_API_END()",
				"}",
			}
			vim.api.nvim_buf_set_lines(0, func.start_row, func.start_row + 1, false, new_func)
		end
	end

	-- Re-parse the buffer after rewriting single-line functions
	parser = vim.treesitter.get_parser(bufnr)
	trees = parser:parse()
	tree = trees[1]
	root = tree:root()

	-- Second pass: insert macros for multi-line functions (if not already present)
	local edits = {}
	local func_defs = {}

	for id, node, _ in func_query:iter_captures(root, bufnr, 0, -1) do
		local name = func_query.captures[id]
		if name == "body" then
			local body_node = node
			local start_row, _, end_row, _ = body_node:range()
			local body_lines = vim.api.nvim_buf_get_lines(0, start_row, end_row + 1, false)
			local has_begin, has_end = false, false
			for _, l in ipairs(body_lines) do
				if l:find("FALCON_C_API_BEGIN") then
					has_begin = true
				end
				if l:find("FALCON_C_API_END") then
					has_end = true
				end
			end
			if not has_begin then
				table.insert(edits, { line = start_row + 1, text = "  FALCON_C_API_BEGIN" })
			end
			if not has_end then
				local parent = body_node:parent()
				local ret_type = ""
				for cid, cnode in func_query:iter_captures(parent, bufnr, 0, -1) do
					if func_query.captures[cid] == "ret_type" then
						ret_type = ts.get_node_text(cnode, bufnr)
					end
				end
				local macro_end = get_macro_end(ret_type)
				if macro_end ~= "" then
					table.insert(edits, { line = end_row, text = "  FALCON_C_API_END(" .. macro_end .. ")" })
				else
					table.insert(edits, { line = end_row, text = "  FALCON_C_API_END()" })
				end
			end
		elseif name == "funcdef" then
			local start_row, _, end_row, _ = node:range()
			table.insert(func_defs, { start = start_row, ["end"] = end_row })
		end
	end

	-- Apply edits in reverse order for multi-line functions
	table.sort(edits, function(a, b)
		return a.line > b.line
	end)
	for _, edit in ipairs(edits) do
		vim.api.nvim_buf_set_lines(0, edit.line, edit.line, false, { edit.text })
	end

	-- Wrap all functions in extern "C" { ... }
	if #func_defs > 0 then
		vim.api.nvim_buf_set_lines(0, func_defs[1].start, func_defs[1].start, false, { 'extern "C" {' })
		local last_line = vim.api.nvim_buf_line_count(0)
		vim.api.nvim_buf_set_lines(0, last_line, last_line, false, { "}" })
	end

	print('FALCON_C_API macros and extern "C" block inserted!')
end

insert_falcon_macros_and_extern_c()
