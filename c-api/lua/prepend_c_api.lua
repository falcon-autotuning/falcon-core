local api = vim.api

local function prepend_c_api()
	local bufnr = api.nvim_get_current_buf()
	local lines = api.nvim_buf_get_lines(bufnr, 0, -1, false)
	local pattern = "^([%w_][%w_%* ]+[%s%*])([%w_]+%s*%()"

	for i, line in ipairs(lines) do
		-- Skip lines that already have FALCON_CORE_C_API
		if not line:find("FALCON_CORE_C_API") then
			local new = line:gsub(pattern, "FALCON_CORE_C_API %1%2")
			if new ~= line then
				lines[i] = new
			end
		end
	end

	api.nvim_buf_set_lines(bufnr, 0, -1, false, lines)
end

return {
	prepend_c_api = prepend_c_api,
}
