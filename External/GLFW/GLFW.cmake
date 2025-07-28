add_library("GLFW" STATIC
  External/GLFW/include/GLFW/glfw3.h
  External/GLFW/include/GLFW/glfw3native.h
  External/GLFW/src/context.c
  External/GLFW/src/egl_context.c
  External/GLFW/src/glfw_config.h
  External/GLFW/src/init.c
  External/GLFW/src/input.c
  External/GLFW/src/monitor.c
  External/GLFW/src/osmesa_context.c
  External/GLFW/src/vulkan.c
  External/GLFW/src/wgl_context.c
  External/GLFW/src/win32_init.c
  External/GLFW/src/win32_joystick.c
  External/GLFW/src/win32_monitor.c
  External/GLFW/src/win32_thread.c
  External/GLFW/src/win32_time.c
  External/GLFW/src/win32_window.c
  External/GLFW/src/window.c
)
set_target_properties("GLFW" PROPERTIES OUTPUT_NAME GLFW)
set_target_properties("GLFW" PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY_DEBUG "External/GLFW/bin/Debug-windows-x86_64/GLFW"
  LIBRARY_OUTPUT_DIRECTORY_DEBUG "External/GLFW/bin/Debug-windows-x86_64/GLFW"
  RUNTIME_OUTPUT_DIRECTORY_DEBUG "External/GLFW/bin/Debug-windows-x86_64/GLFW"
  ARCHIVE_OUTPUT_DIRECTORY_RELEASE "External/GLFW/bin/Release-windows-x86_64/GLFW"
  LIBRARY_OUTPUT_DIRECTORY_RELEASE "External/GLFW/bin/Release-windows-x86_64/GLFW"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "External/GLFW/bin/Release-windows-x86_64/GLFW"
)
target_compile_definitions("GLFW" PRIVATE
  _GLFW_WIN32
  _CRT_SECURE_NO_WARNINGS
)
target_compile_options("GLFW" PRIVATE
  $<$<COMPILE_LANG_AND_ID:C,MSVC>:/MP>
  $<$<CONFIG:Debug>:$<$<COMPILE_LANG_AND_ID:C,MSVC>:/MTd>>
  $<$<CONFIG:Debug>:$<$<COMPILE_LANG_AND_ID:C,MSVC>:/Z7>>
  $<$<CONFIG:Release>:$<$<COMPILE_LANG_AND_ID:C,MSVC>:/Ot>>
  $<$<CONFIG:Release>:$<$<COMPILE_LANG_AND_ID:C,MSVC>:/MT>>
  $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/MP>
  $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/EHsc>
  $<$<CONFIG:Debug>:$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/MTd>>
  $<$<CONFIG:Debug>:$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/Z7>>
  $<$<CONFIG:Release>:$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/Ot>>
  $<$<CONFIG:Release>:$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/MT>>
  $<$<AND:$<NOT:$<C_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<CONFIG:Debug>:$<$<AND:$<NOT:$<C_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:C>>:-g>>
  $<$<CONFIG:Release>:$<$<AND:$<NOT:$<C_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:C>>:-O2>>
  $<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<CONFIG:Debug>:$<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:CXX>>:-g>>
  $<$<CONFIG:Release>:$<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:CXX>>:-O2>>
)
target_link_options("GLFW" PRIVATE
  /NOLOGO
)
