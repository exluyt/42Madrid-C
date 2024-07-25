find . -type f -name "*.sh" | sed 's/\.sh//g' | rev | tr '/' ' ' | awk '{print $1}' | rev
