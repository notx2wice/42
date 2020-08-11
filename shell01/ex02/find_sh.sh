find . -name '*.sh' -type f |xargs basename | sed 's/\.sh$//'
