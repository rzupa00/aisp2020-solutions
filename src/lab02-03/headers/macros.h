/**
 * Macros used in application
 */
#ifndef MACROS_H
    #define MACROS_H

    /**
     * String length limiters
     */
    #define FIRST_NAME_LENGTH  256
    #define LAST_NAME_LENGTH   256
    #define FILE_NAME_LENGTH   256
    #define LINE_BUFFER_LENGTH 1024

    /**
     * Function result return values
     */
    #define RETURN_OK                     0
    #define RETURN_OPERATION_CANCELLED    1
    #define RETURN_WARN_ELEMENT_NOT_FOUND 2
    #define RETURN_WARN_EMPTY_LIST        3
    #define RETURN_WARN_FILE_NOT_OPENED   4
    #define RETURN_ERROR_ALLOC_FAILED    -1
    #define RETURN_ERROR_FILE_NOT_OPENED -2

    /**
     * User menu selection items
     */
    #define USER_MENU_INSERT_TO_BEGINNING   1
    #define USER_MENU_INSERT_TO_END         2
    #define USER_MENU_INSERT_BEFORE_ELEMENT 3
    #define USER_MENU_INSERT_AFTER_ELEMENT  4
    #define USER_MENU_PRINT_TO_CONSOLE      5
    #define USER_MENU_READ_FROM_FILE        6
    #define USER_MENU_PRINT_TO_FILE         7
    #define USER_MENU_DELETE                8
    #define USER_MENU_FIND                  9
    #define USER_MENU_SORT                 10
    #define USER_MENU_EXIT                 -1

    #define USER_SUBMENU_CANCEL_STRING  "-1"
    #define USER_SUBMENU_CANCEL_INTEGER -1

    /**
     * Console screen clearing macros
     */
    #ifdef _WIN32
        #define CLEAR_SCREEN "cls"
    #else
        #define CLEAR_SCREEN "clear"
    #endif
#endif // MACROS_H
