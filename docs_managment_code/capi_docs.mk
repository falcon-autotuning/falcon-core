# docs.mk
.PHONY: docs-all docs-setup docs-run docs-coverage docs-teardown

docs-all: docs-setup docs-run docs-coverage

# Makefile for C/C++ doc porting pipeline

# --------------------------------------------------------------------
# Path configuration (keep in sync with docs_pipeline.yml)
# --------------------------------------------------------------------
CPP_ROOT              := ./cpp
C_API_ROOT            := ./c-api
C_API_ARCHIVE_ROOT    := ./docs_managment_code/archive
C_API_PRISTINE        := $(C_API_ARCHIVE_ROOT)/c-api_no_docs

CPP_INCLUDE_ROOT      := $(CPP_ROOT)/include
C_API_INCLUDE_ROOT    := $(C_API_ROOT)/include

# CPP_METADATA_ROOT     := ./docs_managment_code/cpp_metadata #TODO: update extraction script to use this path
CPP_METADATA_ROOT     := ./cpp_metadata
AUTO_MAPS_DIR         := $(C_API_INCLUDE_ROOT)/falcon_core
USER_MAPS_DIR         := ./docs_managment_code/c-api_user_maps

LOGS_DIR              := ./docs_managment_code/logs

# Python scripts (adjust these names if yours differ)
EXTRACT_CPP_DOCS      := ./docs_managment_code/extract_cpp_docs.py
GENERATE_C_API_MAPS   := ./docs_managment_code/generate_c_api_maps.py
INJECT_C_DOCS         := ./docs_managment_code/inject_c_docs.py
COVERAGE_SCRIPT       := ./docs_managment_code/doxygen_port_coverage.py

PYTHON                := python3

# --------------------------------------------------------------------
# 1) SETUP: backup existing c-api and restore pristine copy
# --------------------------------------------------------------------
docs-setup:
	@echo "==> [setup] Preparing clean c-api directory"
	@if [ ! -d "$(C_API_ARCHIVE_ROOT)" ]; then \
	    echo "Creating archive directory: $(C_API_ARCHIVE_ROOT)"; \
	    mkdir -p "$(C_API_ARCHIVE_ROOT)"; \
	fi
	@if [ -d "$(C_API_ROOT)" ]; then \
	    echo "Existing c-api directory found at $(C_API_ROOT)"; \
	    i=1; \
	    while [ -d "$(C_API_ARCHIVE_ROOT)/c-api_bak$$i" ]; do \
	        i=$$((i+1)); \
	    done; \
	    backup_dir="$(C_API_ARCHIVE_ROOT)/c-api_bak$$i"; \
	    echo "Backing up existing c-api to $$backup_dir"; \
	    mv "$(C_API_ROOT)" "$$backup_dir"; \
	else \
	    echo "No existing c-api directory to back up."; \
	fi
	@if [ ! -d "$(C_API_PRISTINE)" ]; then \
	    echo "ERROR: Pristine archive '$(C_API_PRISTINE)' does not exist."; \
	    echo "       Please ensure docs_managment_code/archive/c-api_no_docs is present."; \
	    exit 1; \
	fi
	@echo "Copying pristine c-api from $(C_API_PRISTINE) to $(C_API_ROOT)"
	@cp -R "$(C_API_PRISTINE)" "$(C_API_ROOT)"

# --------------------------------------------------------------------
# 2) DOCS: run the doc pipeline (extract -> map -> inject)
# --------------------------------------------------------------------
docs-run:
		@echo "==> [docs] Ensuring logs directory exists"
	@mkdir -p "$(LOGS_DIR)"

	@echo "==> [docs] Step 1/3: Extracting C++ Doxygen metadata"
	@$(PYTHON) "$(EXTRACT_CPP_DOCS)" \
	    "$(CPP_INCLUDE_ROOT)" \
		>> "$(LOGS_DIR)/extract_cpp_docs.log"

	@echo "==> [docs] Step 2/3: Generating C API .map.yml files"
	@$(PYTHON) "$(GENERATE_C_API_MAPS)" \
	    --cpp-metadata-root "$(CPP_METADATA_ROOT)" \
	    --cpp-include-root  "$(CPP_INCLUDE_ROOT)" \
	    --c-api-root        "$(C_API_INCLUDE_ROOT)" \
	    --overwrite \
	    --verbose \
	    >> "$(LOGS_DIR)/generate_c_api_maps.log"

	@echo "==> [docs] Step 3/3: Injecting C++ docs into C headers"
	@$(PYTHON) "$(INJECT_C_DOCS)" \
	    --capi-root "$(C_API_ROOT)" \
	    --cpp-root "$(CPP_ROOT)" \
	    --cpp-metadata-root "$(CPP_METADATA_ROOT)" \
	    --maps-dir "$(AUTO_MAPS_DIR)" \
	    --man-maps-dir "$(USER_MAPS_DIR)" \
	    --out-root "$(C_API_ROOT)" \
	    --verbose \
	    >> "$(LOGS_DIR)/inject_c_docs.log"

	@echo "==> [docs] Documentation injection complete."

# --------------------------------------------------------------------
# 3) COVERAGE: track porting progress
# --------------------------------------------------------------------
docs-coverage:
	@echo "==> [coverage] Running documentation coverage report"
	@$(PYTHON) "$(COVERAGE_SCRIPT)" \
	    --cpp-root "$(CPP_ROOT)" \
	    --c-root "$(C_API_ROOT)" \
	    --cpp-metadata-root "$(CPP_METADATA_ROOT)"

# --------------------------------------------------------------------
# 4) TEARDOWN: optional cleanup / restore
#    (kept intentionally minimal/safe; extend if you want)
# --------------------------------------------------------------------
docs-teardown:
	@echo "==> [teardown] No teardown actions defined yet."
	@if [ -d "$(C_API_ROOT)" ]; then \
	    echo "Removing $(C_API_ROOT) ..."; \
	    rm -rf "$(C_API_ROOT)"; \
	    echo "c-api directory removed."; \
	else \
	    echo "No c-api directory found to remove."; \
	fi

# Optional: clean logs and c-api backups once c-api code is fully commented or 
# development is at a stable point
docs-clean:

	@echo "==> [docs-clean] Removing log files in $(LOGS_DIR)"
	@rm -f "$(LOGS_DIR)"/*.log || true

	@echo "==> [docs-clean] Removing c-api backup directories"
	@if [ -d "$(C_API_ARCHIVE_ROOT)" ]; then \
	    bak_dirs=$$(find "$(C_API_ARCHIVE_ROOT)" -maxdepth 1 -type d -name 'c-api_bak*'); \
	    if [ -n "$$bak_dirs" ]; then \
	        echo "Removing backups: $$bak_dirs"; \
	        rm -rf $$bak_dirs; \
	        echo "Backup directories removed."; \
	    else \
	        echo "No c-api_bak* directories found."; \
	    fi \
	else \
	    echo "Archive root $(C_API_ARCHIVE_ROOT) does not exist. Nothing to clean."; \
	fi