#OBJS specifies which files to compile as part of the project 
OBJS = teatime.cxx 

#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = teatime

#This is the target that compiles our executable 
all : $(OBJS)
	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME)
