CXX := g++
CXXFLAGS := -std=c++11
SERVERSOURCES = $(wildcard Server/Commands/*.cpp ) $(wildcard Server/GeneralServerResources/*.cpp ) $(wildcard Server/Iris/*.cpp ) $(wildcard Server/KSmallestAlgo/*.cpp )  $(wildcard Server/ServerIO/*.cpp ) Server/MainServer.cpp  $(wildcard Sockets/*.cpp )
CLIENTSOURCES = $(wildcard Client/ClientIO/*.cpp )  Client/ClientActions.cpp Client/MainClient.cpp $(wildcard Sockets/*.cpp )
server : $(SERVERSOURCES)
	$(CXX) $(CXXFLAGS)  $(SERVERSOURCES) -o serverrun -lpthread
client : $(CLIENTSOURCES)
	$(CXX) $(CXXFLAGS)  $(CLIENTSOURCES) -o clientrun