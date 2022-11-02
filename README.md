# KNN algorithm to determine the type of an iris

**This project was made by Daniel Assa and Daniel Lifshitz.**
## Type finding by server
The server is currently meant to implement the KNN algorithm with iris types, for a given unclassified iris, we find its *K CLOSEST NEIGHBOURS* in $O\left(n\right)$ and from them determine its type,
using the following three different types of irises: *setosa*, *virgincia*, *versicolor*. 
## Threads and server timeout
The server uses threads in order to support more than one client at once (with a max of 5 according to the ```listen()``` function, additionaly if no clients are connected for 1-2 minutes, the server will shutdown.
## Run the code
### Requirements
The client will have a test file which is unclassified and a train file which is classified in his working directory.
An example for a train file:
```
5.4,3.9,1.7,0.4,Iris-versicolor
4.6,3.4,1.4,0.3,Iris-setosa
5.0,3.4,1.5,0.2,Iris-virginica
```
The numbers in each column correspond to a feature of the iris:
1. The iris' width
2. The iris's sepal length
3. The iris's sepal width
4. The iris' petal length
5. The iris' type, from the types stated above.  
The client could also send data with more dimensions than only 4.
  
  

### Compile and run
The project has a given ```Makefile``` for you to use when compiling the code.
In order to compile the server code type in:
```
make server
```
and to run it:
```
./serverrun
```
And the same goes for the client, run this client command after you've run the server command (and while it's running):
```
make client
```
and to run it:
```
./clientrun  
```
***In Linux.***    
After running the client, the client will be presented with a menu, like so:
```
Welcome to the KNN Classifier Server. Please choose an option:
1. upload an unclassified csv data file
2. algorithm settings
3. classify data
4. display results
5. download results
6. display algorithm confusion matrix
7. exit
```
*1.* You will be asked to input the path for a train file and a test file, the train file will contain the true classes of the test file, this is needed to test the   algorithms accuaracy in option 6,

The test file should look like this:  
```
4.6,3.1,1.5,0.2
6.9,3.1,4.9,1.5
6.3,3.3,6,2.5
6.5,2.8,4.6,1.5
6.4,3.2,4.5,1.5
4.7,3.2,1.3,0.2
```
And the train file should look like this:  
```
5.4,3.9,1.7,0.4,Iris-setosa
4.6,3.4,1.4,0.3,Iris-setosa
5.0,3.4,1.5,0.2,Iris-setosa
4.4,2.9,1.4,0.2,Iris-setosa
4.9,3.1,1.5,0.1,Iris-setosa
5.4,3.7,1.5,0.2,Iris-setosa
```
Keep in mind that these files should be in the client's working directory.    
*2.* change the algorithm settings, You will be shown the current settings:  
```
The current KNN parameters are: K = 5, distance metric = EUC
```
and if for example you want to change it to use $k=3$ and a ```MAN``` metric, you need to input:  
```
3 MAN
```
if you don't want to change the settings, press ```enter``` and continue.  
*3.* This option classifies the test data. (Doesn't send it to you).  
*4.* This option shows you the results of the classification in the terminal screen (regular output).  
Press another space to exit it.  
*5.* This option will ask you for a ```.txt``` file, and send the same data that is shown in option 4 to that file.  
Press another space to exit it.  
The file doesn't have to exist, it can be created for the client.  
*6.* This option prints the confusion matrix for classifier.  
It classifies the number in the train file, and compares them to their classifications.
*7.* Exit from the server.  



### Files in working directories
You must both the train and test files in the client's working directory.






