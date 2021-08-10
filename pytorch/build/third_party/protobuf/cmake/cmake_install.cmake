# Install script for directory: /home/lichangheng/robo_ws/pytorch/third_party/protobuf/cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libprotobuf-lite")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/lib/libprotobuf-lite.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libprotobuf")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/lib/libprotobuf.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libprotoc")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/lib/libprotoc.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protoc")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/protoc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/protoc")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/protoc"
         RPATH "$ORIGIN")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/bin/protoc")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/protoc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/protoc")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/protoc"
         OLD_RPATH ":::::::"
         NEW_RPATH "$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/protoc")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE MESSAGE_NEVER FILES
    "/home/lichangheng/robo_ws/pytorch/build/third_party/protobuf/cmake/protobuf.pc"
    "/home/lichangheng/robo_ws/pytorch/build/third_party/protobuf/cmake/protobuf-lite.pc"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "any.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/any.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "any.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/any.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "api.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/api.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "arena.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/arena.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "arena_impl.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/arena_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "arenastring.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/arenastring.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler" TYPE FILE MESSAGE_NEVER RENAME "code_generator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/code_generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler" TYPE FILE MESSAGE_NEVER RENAME "command_line_interface.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/command_line_interface.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/cpp" TYPE FILE MESSAGE_NEVER RENAME "cpp_generator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/cpp/cpp_generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/csharp" TYPE FILE MESSAGE_NEVER RENAME "csharp_generator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/csharp/csharp_generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/csharp" TYPE FILE MESSAGE_NEVER RENAME "csharp_names.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/csharp/csharp_names.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler" TYPE FILE MESSAGE_NEVER RENAME "importer.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/importer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/java" TYPE FILE MESSAGE_NEVER RENAME "java_generator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/java/java_generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/java" TYPE FILE MESSAGE_NEVER RENAME "java_names.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/java/java_names.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/js" TYPE FILE MESSAGE_NEVER RENAME "js_generator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/js/js_generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/js" TYPE FILE MESSAGE_NEVER RENAME "well_known_types_embed.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/js/well_known_types_embed.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/objectivec" TYPE FILE MESSAGE_NEVER RENAME "objectivec_generator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/objectivec/objectivec_generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/objectivec" TYPE FILE MESSAGE_NEVER RENAME "objectivec_helpers.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/objectivec/objectivec_helpers.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler" TYPE FILE MESSAGE_NEVER RENAME "parser.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/parser.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/php" TYPE FILE MESSAGE_NEVER RENAME "php_generator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/php/php_generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler" TYPE FILE MESSAGE_NEVER RENAME "plugin.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/plugin.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler" TYPE FILE MESSAGE_NEVER RENAME "plugin.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/plugin.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/python" TYPE FILE MESSAGE_NEVER RENAME "python_generator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/python/python_generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler/ruby" TYPE FILE MESSAGE_NEVER RENAME "ruby_generator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/ruby/ruby_generator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "descriptor.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/descriptor.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "descriptor.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/descriptor.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "descriptor_database.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/descriptor_database.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "duration.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/duration.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "dynamic_message.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/dynamic_message.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "empty.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/empty.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "extension_set.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/extension_set.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "field_mask.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/field_mask.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "generated_enum_reflection.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/generated_enum_reflection.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "generated_enum_util.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/generated_enum_util.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "generated_message_reflection.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/generated_message_reflection.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "generated_message_table_driven.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/generated_message_table_driven.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "generated_message_util.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/generated_message_util.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "has_bits.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/has_bits.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "implicit_weak_message.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/implicit_weak_message.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "inlined_string_field.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/inlined_string_field.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/io" TYPE FILE MESSAGE_NEVER RENAME "coded_stream.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/io/coded_stream.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/io" TYPE FILE MESSAGE_NEVER RENAME "gzip_stream.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/io/gzip_stream.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/io" TYPE FILE MESSAGE_NEVER RENAME "printer.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/io/printer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/io" TYPE FILE MESSAGE_NEVER RENAME "strtod.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/io/strtod.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/io" TYPE FILE MESSAGE_NEVER RENAME "tokenizer.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/io/tokenizer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/io" TYPE FILE MESSAGE_NEVER RENAME "zero_copy_stream.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/io/zero_copy_stream.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/io" TYPE FILE MESSAGE_NEVER RENAME "zero_copy_stream_impl.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/io/zero_copy_stream_impl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/io" TYPE FILE MESSAGE_NEVER RENAME "zero_copy_stream_impl_lite.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/io/zero_copy_stream_impl_lite.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "map.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/map.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "map_entry.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/map_entry.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "map_entry_lite.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/map_entry_lite.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "map_field.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/map_field.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "map_field_inl.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/map_field_inl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "map_field_lite.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/map_field_lite.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "map_type_handler.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/map_type_handler.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "message.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/message.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "message_lite.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/message_lite.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "metadata.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/metadata.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "metadata_lite.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/metadata_lite.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "reflection.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/reflection.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "reflection_ops.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/reflection_ops.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "repeated_field.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/repeated_field.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "service.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/service.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "source_context.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/source_context.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "struct.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/struct.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "bytestream.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/bytestream.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "callback.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/callback.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "casts.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/casts.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "common.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/common.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "fastmem.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/fastmem.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "hash.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/hash.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "logging.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/logging.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "macros.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/macros.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "mutex.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/mutex.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "once.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/once.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "platform_macros.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/platform_macros.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "port.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/port.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "singleton.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/singleton.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "status.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/status.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "stl_util.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/stl_util.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "stringpiece.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/stringpiece.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/stubs" TYPE FILE MESSAGE_NEVER RENAME "template_util.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/stubs/template_util.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "text_format.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/text_format.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "timestamp.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/timestamp.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "type.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/type.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "unknown_field_set.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/unknown_field_set.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/util" TYPE FILE MESSAGE_NEVER RENAME "delimited_message_util.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/util/delimited_message_util.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/util" TYPE FILE MESSAGE_NEVER RENAME "field_comparator.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/util/field_comparator.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/util" TYPE FILE MESSAGE_NEVER RENAME "field_mask_util.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/util/field_mask_util.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/util" TYPE FILE MESSAGE_NEVER RENAME "json_util.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/util/json_util.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/util" TYPE FILE MESSAGE_NEVER RENAME "message_differencer.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/util/message_differencer.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/util" TYPE FILE MESSAGE_NEVER RENAME "time_util.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/util/time_util.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/util" TYPE FILE MESSAGE_NEVER RENAME "type_resolver.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/util/type_resolver.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/util" TYPE FILE MESSAGE_NEVER RENAME "type_resolver_util.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/util/type_resolver_util.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "wire_format.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/wire_format.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "wire_format_lite.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/wire_format_lite.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "wire_format_lite_inl.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/wire_format_lite_inl.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "wrappers.pb.h" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/wrappers.pb.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "any.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/any.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "api.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/api.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler" TYPE FILE MESSAGE_NEVER RENAME "plugin.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/plugin.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "descriptor.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/descriptor.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "duration.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/duration.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "empty.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/empty.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "field_mask.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/field_mask.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "source_context.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/source_context.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "struct.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/struct.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "timestamp.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/timestamp.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "type.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/type.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "wrappers.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/wrappers.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "descriptor.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/descriptor.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "any.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/any.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "api.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/api.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "duration.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/duration.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "empty.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/empty.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "field_mask.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/field_mask.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "source_context.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/source_context.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "struct.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/struct.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "timestamp.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/timestamp.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "type.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/type.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf" TYPE FILE MESSAGE_NEVER RENAME "wrappers.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/wrappers.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-protos")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/google/protobuf/compiler" TYPE FILE MESSAGE_NEVER RENAME "plugin.proto" FILES "/home/lichangheng/robo_ws/pytorch/third_party/protobuf/src/google/protobuf/compiler/plugin.proto")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-export")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/protobuf/protobuf-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/protobuf/protobuf-targets.cmake"
         "/home/lichangheng/robo_ws/pytorch/build/third_party/protobuf/cmake/CMakeFiles/Export/lib/cmake/protobuf/protobuf-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/protobuf/protobuf-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/protobuf/protobuf-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/protobuf" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/third_party/protobuf/cmake/CMakeFiles/Export/lib/cmake/protobuf/protobuf-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/protobuf" TYPE FILE MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/third_party/protobuf/cmake/CMakeFiles/Export/lib/cmake/protobuf/protobuf-targets-release.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "protobuf-export")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/protobuf" TYPE DIRECTORY MESSAGE_NEVER FILES "/home/lichangheng/robo_ws/pytorch/build/third_party/protobuf/cmake/lib/cmake/protobuf/" REGEX "/protobuf\\-targets\\.cmake$" EXCLUDE)
endif()

