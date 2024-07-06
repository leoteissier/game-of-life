find_path(CUNIT_INCLUDE_DIR NAMES CUnit/Basic.h)
find_library(CUNIT_LIBRARY NAMES cunit)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CUnit DEFAULT_MSG CUNIT_INCLUDE_DIR CUNIT_LIBRARY)

if(CUNIT_FOUND)
    set(CUNIT_LIBRARIES ${CUNIT_LIBRARY})
    set(CUNIT_INCLUDE_DIRS ${CUNIT_INCLUDE_DIR})
else()
    set(CUNIT_LIBRARIES "")
    set(CUNIT_INCLUDE_DIRS "")
endif()

mark_as_advanced(CUNIT_INCLUDE_DIR CUNIT_LIBRARY)
