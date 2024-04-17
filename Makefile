all: readme
readme:
	python3 scripts/gen-readme.py > README.md