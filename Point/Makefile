

TARGET := Point
OBJECT := Point.o PointMain.o
MK_SYM := -g
MK_OBJ := -c
CPPFLAGS = $(MK_SYM)

GDB := gdb

Point.exe: $(OBJECT)
	$(CXX) $(CPPFLAGS) -o $@ $^ 

Point.o: Point.h Point.cpp
	$(CXX) $(CPPFLAGS) $(MK_OBJ) $^

PointMain.o: PointMain.cpp
	$(CXX) $(CPPFLAGS) $(MK_OBJ) $<

run:
	./$(TARGET).exe

debug:
	$(GDB) ./$(TARGET).exe

clean:
	$(RM) ./$(TARGET).exe $(OBJECT)	
