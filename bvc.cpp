#include<iostream>
#include<vector>
using namespace std;
int n;
struct Case{
	int min;
	int max;
	int close_to_min;
	int close_to_max;
	int nom;
};
vector<vector<int>> test_cases;

void value_input(int value, vector<int> output,int index){
		output.insert(output.begin()+index,value);
		test_cases.push_back(output);	
}

int print_test_cases(int id){
	for(int i=0;i<test_cases.size();i++){
		cout<<"Test id "<<id++<<", ";
		for(int j=0;j<test_cases[i].size();j++){
			if(j==test_cases[i].size()-1){
				cout<<test_cases[i][j]<<endl;
			}
			else cout<<test_cases[i][j]<<",";
		}
	}
	return id;
}

int main(){
	cin>>n;
	struct Case boundaries[n];
	
	for(int i=0;i<n;i++){
		cin>>boundaries[i].min>>boundaries[i].max;
		boundaries[i].close_to_min = boundaries[i].min+1;
		boundaries[i].close_to_max = boundaries[i].max-1;
		boundaries[i].nom = (boundaries[i].min+boundaries[i].max)/2;
	}
	
	for(int i=n-1;i>=0;i--){
		vector<int> output;
		for(int j=0;j<n;j++){
			if(j==i && n>1){
				continue;
			}
			else{
				output.push_back(boundaries[j].nom);
			}
		}
		
		value_input(boundaries[i].min, output, i);
		value_input(boundaries[i].close_to_min, output, i);
		value_input(boundaries[i].max, output, i);
		value_input(boundaries[i].close_to_max, output, i);
	
	}	
	int id=print_test_cases(10000);
	cout<<"Test id "<<id++<<", ";
	for(int i=0;i<n;i++){
		if(i==n-1){
			cout<<boundaries[i].nom<<endl;
		}
		else cout<<boundaries[i].nom<<",";
	}
}
