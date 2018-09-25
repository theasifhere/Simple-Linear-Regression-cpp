#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
//=============Identifiers======================//
void populateDataSets(vector<int>&, vector<int>&);
void printDataSet(vector<int>&, char);
void printValue(int);
double calculateMean(vector<int>&);
double calc_Beta1(vector<int>&, vector<int>&, double, double);
double calc_Beta0(double, double, double);


int main() {
	vector<int> X_vector;
	vector<int> Y_vector;
	double X_mean, Y_mean;
	double beta0, beta1;
	
	cout << "\t================= Linear Regression Cpp =================\n";
	populateDataSets(X_vector, Y_vector);
	
	/*system("cls");*/

	X_mean = calculateMean(X_vector);
	Y_mean = calculateMean(Y_vector);

	printDataSet(X_vector, 'X');
	printDataSet(Y_vector, 'Y');

	beta1 = calc_Beta1(X_vector, Y_vector, X_mean, Y_mean);
	beta0 = calc_Beta0(X_mean, Y_mean, beta1);

	if(beta1 > 0)
		cout << "Linear Regression Formula is: " << beta0 << " + " << beta1 << " x" << endl;
	else
		cout << "Linear Regression Formula is: " << beta0 << " " << beta1 << " x" << endl<<endl;

	cout << "Graph points are : ";
	int x = 10;
	for (int j = 0; j < X_vector.size(); j++) {
		cout << (beta0 + beta1 * x)<<"  ";
		x += 10;
	}
	cout << endl;
	system("pause");
	return 0;
}

//===========Functions Definitions=========================//
void populateDataSets(vector<int>& X_vector, vector<int>& Y_vector){
	size_t n;
	int input;
	cout << "Enter the size of Dataset: ";
	cin >> n;
	cout << "Enter Values of Independant variable (X)\n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		if (cin.fail()) 
		{
			cout << "Invalid number\n";
			cin.clear(); cin.ignore();
			i--;
		}
		else
		{
			X_vector.push_back(input);
		}
		
	}
	cout << "Enter Values of Dependant variable (Y)\n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		if (cin.fail())
		{
			cout << "Invalid number";
			i--;
		}
		else
		{
			Y_vector.push_back(input);
		}

	}
	return;
}
void printDataSet(vector<int>& G_vector, char datasetName) {
	cout << "\n\nDataSet "<< datasetName<<": ";
	for_each(G_vector.begin(), G_vector.end(), printValue);
	cout << endl;
}
void printValue(int i) {
	cout << " " << i;
}
double calculateMean(vector<int>& G_vector) {
	double sum = 0.0;
	for (size_t i = 0; i < G_vector.size(); i++)
	{
		sum+=G_vector[i];
	}
	return sum/G_vector.size();
}

double calc_Beta1(vector<int>& X_vector, vector<int>&Y_vector, double x_mean, double y_mean)
{
	size_t n = X_vector.size();
	double nominator = 0;
	double denominator = 0;
	for (size_t i = 0; i < n; i++)
	{
		nominator = nominator + ((X_vector[i] - x_mean) * (Y_vector[i] - y_mean));

		denominator = denominator + (pow((X_vector[i] - x_mean), 2));
	}
	cout << "Beta-1 is: " << nominator / denominator << endl;
	return nominator / denominator;
}

double calc_Beta0(double x_mean, double y_mean, double beta1)
{
	cout<<"Beta-0 =  " << y_mean - (beta1 * x_mean) <<endl<<endl;
	return y_mean - (beta1 * x_mean);
}
//https://www.w3schools.com/code/tryit.asp?filename=FVL6GSJUQ2ZF
///Developed by Asif Iqbal. @ twitter.com/theasifhere