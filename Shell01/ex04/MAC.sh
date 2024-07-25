ifconfig | grep -v '^\s*$' | awk '/ether/ {print $2}'
