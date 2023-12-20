#include "io.h"

#include <iostream>
#include <string>

using namespace std;

void PrintStudent(const Student& student) {
    const char* name = student.Name();
    std::cout << "Student's name: " << name << std::endl;
}

// Affiche la description d'une classe (sur une ligne) et de tous les étudiants qui y sont inscrits (un par ligne)
void PrintClass(const Class& Cl){
	cout << "Nom : " << Cl.Name() << ", nombre max : " << Cl.MaxNumberOfStudents() << endl;
	for(int i = 0; i < Cl.MaxNumberOfStudents(); i++){
		Student* current = Cl.GetStudent(i);
		if(current != nullptr){
			cout << "Nom : " << current->Name() << ", anniversaire : " << current->Birthday() << endl;
		}
	}
}


// Crée et remplit un Student (nom, date de naissance) avec l'entrée interactive cin, et en utilisant l'opérateur new
Student* EnterStudent(){
	string name;
	int birthday;
	cout << "Nom de l'élève : ";
	cin >> name;
	cout << "Date d'anniversaire : ";
	cin >> birthday;
	return new Student(name.c_str(), birthday);
}


// Fait la même chose pour une classe, puis qui demande le nombre d'étudiants a inscrire, et qui les saisit un par un et les ajoute.
Class* EnterClass(){
	int N;
	string name;
	cout << "Nom de la classe : ";
	cin >> name;
	cout << "Nombre max d'élèves : ";
	cin >> N;

	Class* Cl = new Class(name, N);

	for(int i=0; i < N; i++){
		Cl->AddStudent(EnterStudent());
	}

	return Cl;
}