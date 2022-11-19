Somehow dyld cannot find the lib -- the search path is wrong, so I had to
manually set the env-var via `export DYLD_LIBRARY_PATH=...`