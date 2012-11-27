TARGET = QueueTest1
EXEC_EXT = .exe
GDB = gdb
CPPFLAGS = -g
QT_FILE = QueueTest1.o
QT_MAIN = QueueMain.o
OBJECT = $(QT_FILE) $(QT_MAIN)

$(TARGET)$(EXEC_EXT): $(OBJECT)
	$(CXX) $(CPPFLAGS) -o $(TARGET)$(EXEC_EXT) $^

$(QT_FILE): $(TARGET).h $(TARGET).cpp
	$(CXX) $(CPPFLAGS) -c $^

$(QT_MAIN): $(QT_MAIN:.o=.cpp)
	$(CXX) $(CPPFLAGS) -c $^

run:
	./$(TARGET)$(EXEC_EXT)

debug:
	$(GDB) ./$(TARGET)$(EXEC_EXT)

clean:
	$(RM) ./$(TARGET)$(EXEC_EXT) $(QT_FILE) $(QT_MAIN)
