#!/bin/bash
# **************************************************************************** #
#                                                                              #
#    gen_single_header.sh                                                      #
#                                                                              #
#    Generate STB-style single-header library from modular sources.            #
#    Usage: ./scripts/gen_single_header.sh > release/libft.h                   #
#                                                                              #
# **************************************************************************** #

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
HEADER_FILE="$PROJECT_ROOT/includes/libft.h"
SOURCE_DIR="$PROJECT_ROOT/srcs"

# Module order (logical grouping)
MODULES=(
	"ft_is"
	"ft_mem"
	"ft_str"
	"ft_put"
	"ft_printf"
	"ft_lst"
	"ft_vec"
	"ft_deque"
	"ft_vec_math"
)

# Function to process a source file
# Strips 42 header, removes #include "libft.h", and renames static helpers
process_source() {
	local src_file="$1"
	local filename=$(basename "$src_file" .c)
	# Create prefix from filename (remove ft_ prefix and _bonus suffix)
	local prefix=$(echo "$filename" | sed 's/^ft_//' | sed 's/_bonus$//')

	# First pass: find static function names (non ft_ prefixed)
	local static_funcs=$(grep -E '^static[ 	]+(int|void|char|size_t|long|unsigned)[ 	]+[a-z_]+[ 	]*\(' "$src_file" 2>/dev/null | \
		sed -E 's/^static[ 	]+(int|void|char|size_t|long|unsigned)[ 	]+([a-z_]+)[ 	]*\(.*/\2/' | \
		grep -v '^ft_' || true)

	# Build sed commands for renaming
	local sed_cmds=""
	for func in $static_funcs; do
		sed_cmds="$sed_cmds -e s/${func}/${prefix}__${func}/g"
	done

	# Process the file: strip header, strip include, apply renames
	awk '
		BEGIN { in_header = 1; header_lines = 0 }
		in_header && header_lines < 12 && /^\/\*|^\*\*|^\*\/|^[ 	]*\*/ {
			header_lines++
			next
		}
		{ in_header = 0 }
		/^# *include.*"libft\.h"/ { next }
		NR == header_lines + 1 && /^$/ { next }
		{ print }
	' "$src_file" | if [ -n "$sed_cmds" ]; then sed $sed_cmds; else cat; fi
}

# Output the header section (declarations)
# Remove the final #endif, we'll add it back after implementation
sed '$ d' "$HEADER_FILE"

# Start implementation section
cat << 'IMPL_START'

/* ************************************************************************** */
/*                                                                            */
/*                         IMPLEMENTATION SECTION                             */
/*                                                                            */
/*    Define LIBFT_IMPLEMENTATION in exactly one .c file before including     */
/*    this header to create the implementation.                               */
/*                                                                            */
/* ************************************************************************** */

#ifdef LIBFT_IMPLEMENTATION

IMPL_START

# Process each module in order
for module in "${MODULES[@]}"; do
	module_dir="$SOURCE_DIR/$module"
	if [ -d "$module_dir" ]; then
		# Add module separator comment
		printf '\n/* '
		printf '=%.0s' {1..74}
		printf ' */\n'
		printf '/*%38s%-38s*/\n' "$module " ""
		printf '/* '
		printf '=%.0s' {1..74}
		printf ' */\n\n'

		# Find and process all .c files in this module
		find "$module_dir" -name '*.c' -type f | sort | while read -r src_file; do
			filename=$(basename "$src_file")
			printf '/* --- %s --- */\n\n' "$filename"
			process_source "$src_file"
			printf '\n'
		done
	fi
done

# Close implementation section
cat << 'IMPL_END'

#endif /* LIBFT_IMPLEMENTATION */

#endif /* LIBFT_H */
IMPL_END
