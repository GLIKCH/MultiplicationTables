/////////////////////////
// Joel De Alba        //
// 8 / 17 / 22         //
// CS - 210            //
// Week 6 Assignment   //
/////////////////////////

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

// Provided Code by SNHU CS-210 // // // // // // // // // // // // // // // // // // // // // // // // // //

/*Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/

// Calls Python function without parameters

void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/

// Function overloading to call integer function with parameters from Python

int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

// Function overloading to call integer function with parameters from Python

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

// End of Provided Code by SNHU CS-210 // // // // // // // // // // // // // // // // // // // // // // // //

int main()
{
	while (true)														// While user input returns a value
	{
		int num;														// Declares variable placeholder for user input
		cout << "\n1:Display a multiplication table";					// Prints first user input option to console
		cout << "\n2:Double a value";									// Prints second user input option to console
		cout << "\n3 : Exit" << endl;									// Prints third user input option to console
		cout << "\nEnter your selection as a number 1, 2 or 3: ";		// Prints recollection of available options
		cin >> num;														// Stores user input menu option to "num"

		if (num == 1)													// If user input is #1 then call MultiplicationTable Function from Python
		{
			callIntFunc("MultiplicationTable", "num");
		}
		else if (num == 2)												// If user input is #2 then call DoubleMult Function from Python
		{
			callIntFunc("DoubleMult", "num");
		}
		else if (num == 3)												// If user input is #3 then print end of program to console and end program
		{
			cout << endl << "Thank You, Have a Nice Day!";
			cout << endl << "End of Program" << endl;
			break;
		}
		else															// If user input is any other character then ask user for re-attempt
		{
			cout << "Sorry, Incorrect Value, Please Try Again! (Options are: 1, 2, or 3)" << endl;
		}
	}
	return 0;															// Returns 0 and ends program
}