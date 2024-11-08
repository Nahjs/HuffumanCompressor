cmake_minimum_required(VERSION 3.14)  # 确保使用适当的 CMake 版本
project(MyProjectName VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 查找 Qt 模块
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# 添加源文件
set(SOURCES
        filetree.cpp
        hufEncode.cpp
        hufDecode.cpp
        hufBase.cpp
        main.cpp
        mainwindow.cpp
)

# 添加头文件
set(HEADERS
        filetree.h
        hufEncode.h
        hufDecode.h
        hufBase.h
        mainwindow.h
        type.h
)

# 添加 UI 文件
set(FORMS
        mainwindow.ui
)

# 自动处理 UI 文件
qt6_wrap_ui(UI_HEADERS ${FORMS})


# 自动处理资源文件
qt6_add_resources(RESOURCES_FILES "${RESOURCES}")

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UI_HEADERS} ${RESOURCES_FILES})

# 链接 Qt 库
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Widgets)

# 安装规则
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
