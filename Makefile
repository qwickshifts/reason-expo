project_name = reason-expo

DUNE = opam exec -- dune

.DEFAULT_GOAL := help

.PHONY: help
help: ## Print this help message
	@echo "List of available make commands";
	@echo "";
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}';
	@echo "";

.PHONY: nuke
nuke: ## Delete all files that will be generated
	rm $(project_name).opam
	rm -rf node_modules
	rm -rf _build
	rm -rf _opam

.PHONY: create-switch
create-switch: ## Create opam switch
	opam switch create . -y --deps-only --no-install --packages=dune

.PHONY: init
init: create-switch install ## Configure everything to develop this repository in local

.PHONY: generate-opam
generate-opam: ## Generate the opam file
	$(DUNE) build $(project_name).opam

.PHONY: install
install: generate-opam ## Install development dependencies
	yarn install
	opam update
	opam install -y . --deps-only --with-test --with-dev-setup
	opam exec opam-check-npm-deps

.PHONY: build
build: ## Build the project
	$(DUNE) build

.PHONY: watch
watch: ## Watch for the filesystem and rebuild on every change
	$(DUNE) build --watch

.PHONY: test
test: 
	yarn test

.PHONY: clean
clean: ## Clean build artifacts and other generated files
	$(DUNE) clean

.PHONY: format
format: ## Format the codebase with ocamlformat
	$(DUNE) build @fmt --auto-promote

.PHONY: format-check
format-check: ## Checks if format is correct
	$(DUNE) build @fmt
