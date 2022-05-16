function(nodeeditor_print_variables_table)
	set(options)
	set(oneValueArgs)
	set(multiValueArgs TITLE VARIABLES)

	cmake_parse_arguments(VARS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	if(VARS_UNPARSED_ARGUMENTS)
    	message(FATAL_ERROR "Unknown keywords given to nodeeditor_print_variables_table(): \"${CPP_UNPARSED_ARGUMENTS}\"")
    	return()
  	endif()

  	if(NOT VARS_VARIABLES)
    	message(FATAL_ERROR "Required argument VARIABLES missing in nodeeditor_print_variables_table() call")
    	return()
  	endif()

	# Calculate title width
	set(TITLE_MAXIMUM_WIDTH 0)
	if(VARS_TITLE)
		foreach(line ${VARS_TITLE})
			string(LENGTH "${line}" TITLE_LENGTH)
			if(TITLE_LENGTH GREATER TITLE_MAXIMUM_WIDTH)
				set(TITLE_MAXIMUM_WIDTH ${TITLE_LENGTH})
			endif()
		endforeach()
	endif()

	# Calculate column width
	set(KEY_MAXIMUM_WIDTH 0)
	set(VAL_MAXIMUM_WIDTH 0)

	foreach(var ${VARS_VARIABLES})
		string(LENGTH "${var}" KEY_LENGTH)
		string(LENGTH "${${var}}" VAL_LENGTH)
		if(KEY_LENGTH GREATER KEY_MAXIMUM_WIDTH)
			set(KEY_MAXIMUM_WIDTH ${KEY_LENGTH})
		endif()
		if(VAL_LENGTH GREATER VAL_MAXIMUM_WIDTH)
			set(VAL_MAXIMUM_WIDTH ${VAL_LENGTH})
		endif()
	endforeach()

	if(VARS_TITLE)
		math(EXPR COLUMNS_LENGTH "${KEY_MAXIMUM_WIDTH} + ${VAL_MAXIMUM_WIDTH} + 3")
		if(${COLUMNS_LENGTH} GREATER ${TITLE_MAXIMUM_WIDTH})
			set(TITLE_MAXIMUM_WIDTH ${COLUMNS_LENGTH})
		else()
			math(EXPR VAL_MAXIMUM_WIDTH "${TITLE_MAXIMUM_WIDTH} - ${KEY_MAXIMUM_WIDTH} - 3")
		endif()

		# Print line
		string(REPEAT "═" ${TITLE_MAXIMUM_WIDTH} TITLE_LINE_SPACER)
		message("╔═${TITLE_LINE_SPACER}═╗")

		# Print title
		foreach(line ${VARS_TITLE})
			string(LENGTH "${line}" TITLE_LENGTH)
			math(EXPR TITLR_SPACER_LENGTH "${TITLE_MAXIMUM_WIDTH} - ${TITLE_LENGTH}")
			string(REPEAT " " ${TITLR_SPACER_LENGTH} TITLE_SPACER)
			message("║ ${line}${TITLE_SPACER} ║")
		endforeach()

	endif()


	# Print line
	string(REPEAT "═" ${KEY_MAXIMUM_WIDTH} KEY_LINE_SPACER)
	string(REPEAT "═" ${VAL_MAXIMUM_WIDTH} VAL_LINE_SPACER)
	if(VARS_TITLE)
		message("╠═${KEY_LINE_SPACER}═╦═${VAL_LINE_SPACER}═╣")
	else()
		message("╔═${KEY_LINE_SPACER}═╦═${VAL_LINE_SPACER}═╗")
	endif()

	# Print table body
	foreach(var ${VARS_VARIABLES})
		string(LENGTH "${var}" KEY_LENGTH)
		string(LENGTH "${${var}}" VAL_LENGTH)
		math(EXPR KEY_SPACER_LENGTH "${KEY_MAXIMUM_WIDTH} - ${KEY_LENGTH}")
		math(EXPR VAL_SPACER_LENGTH "${VAL_MAXIMUM_WIDTH} - ${VAL_LENGTH}")
		string(REPEAT " " ${KEY_SPACER_LENGTH} KEY_SPACER)
		string(REPEAT " " ${VAL_SPACER_LENGTH} VAL_SPACER)
		message("║ ${var}${KEY_SPACER} ║ ${${var}}${VAL_SPACER} ║")
	endforeach()

	# Print line
	message("╚═${KEY_LINE_SPACER}═╩═${VAL_LINE_SPACER}═╝")

endfunction()
