set(SOURCES
		resources.qrc

		main.cpp
		Node.cpp
		MainWindow.cpp
		Editor.cpp
		Sidebar.cpp
		ConnectionPoint.cpp
		Connection.cpp

		LogicGates/PowerSource.cpp
		LogicGates/DisplayOutput.cpp
		LogicGates/AbstractTwoInputNode.cpp
		LogicGates/Gates/XorGate.cpp
		LogicGates/Gates/AndGate.cpp
		LogicGates/Gates/OrGate.cpp
		LogicGates/Gates/BufferGate.cpp
		LogicGates/Gates/TriStateBufferGate.cpp

)

set(HEADERS
		# We only need to include the headers that have a QOBJECT macro call in them.
		../include/AbstractNode.hpp
		../include/Node.hpp
		../include/ConnectionPoint.hpp
		../include/Connection.hpp
		../include/MainWindow.hpp
		../include/Editor.hpp
		../include/Sidebar.hpp


)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)
