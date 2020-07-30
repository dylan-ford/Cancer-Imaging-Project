//Name: Dylan Ford
//Date: Dec 10, 2019
//Description: Contains file reading and printing methods to help reduce code in the main
#pragma once
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

#include "Patient.hpp"
#include "Graph.hpp"

//Desc: reads in the wisconsin data set into the patient vector
//Parms: vector of patient objects
//Return: n/a
inline void readInCSV(std::vector<Patient*>* patientVector) {

	std::string line, val;

	

	std::fstream fin;
	fin.open("wisconsin data.csv", std::ios::in);

	while (getline(fin, line)) //read in a whole line and store it in line variable
	{
		std::stringstream ss(line); // stringstream object on the line

		Patient* patient = new Patient();

		getline(ss, val, ',');
		patient->patientId_ = stoi(val);

		getline(ss, val, ',');
		patient->clump_ = stoi(val);

		getline(ss, val, ',');
		patient->cellSize_ = stoi(val);

		getline(ss, val, ',');
		patient->cellShape_ = stoi(val);

		getline(ss, val, ',');
		patient->mAdhesion_ = stoi(val);

		getline(ss, val, ',');
		patient->seCellSize_ = stoi(val);

		getline(ss, val, ',');
		if (val == "?")
		{
			patient->bareNuclei_ = 1;
		}
		else
			patient->bareNuclei_ = stoi(val);

		getline(ss, val, ',');
		patient->chromatin_ = stoi(val);

		getline(ss, val, ',');
		patient->nucleoli_ = stoi(val);

		getline(ss, val, ',');
		patient->mitosis_ = stoi(val);

		getline(ss, val, ',');
		patient->diagnosis_ = stoi(val);

		patientVector->push_back(patient);
	}
	fin.close();
}

//Desc: reads in the risk factor data set into the patient vector
//Parms: vector of patient objects
//Return: n/a
inline void readInRF(std::vector<Patient*>* patientVector) {
	std::string line, val;

	int i = 0;

	std::fstream fin;
	fin.open("risk factor data.csv", std::ios::in);

	while (getline(fin, line)) //read in a whole line and store it in line variable
	{
		std::stringstream ss(line); // stringstream object on the line

		getline(ss, val, ',');

		getline(ss, val, ',');
		if (val == "T")
		{
			patientVector->at(i)->risk_factor.Gender = true;
		}
		else if (val == "F")
		{
			patientVector->at(i)->risk_factor.Gender = false;
		}

		getline(ss, val, ',');
		if (val == "T")
		{
			patientVector->at(i)->risk_factor.Age = true;
		}
		else if (val == "F")
		{
			patientVector->at(i)->risk_factor.Age = false;
		}

		getline(ss, val, ',');
		if (val == "T")
		{
			patientVector->at(i)->risk_factor.GeneticFactor = true;
		}
		else if (val == "F")
		{
			patientVector->at(i)->risk_factor.GeneticFactor = false;
		}

		getline(ss, val, ',');
		if (val == "T")
		{
			patientVector->at(i)->risk_factor.FamilyHistory = true;
		}
		else if (val == "F")
		{
			patientVector->at(i)->risk_factor.FamilyHistory = false;
		}

		getline(ss, val, ',');
		if (val == "T")
		{
			patientVector->at(i)->risk_factor.Overweight = true;
		}
		else if (val == "F")
		{
			patientVector->at(i)->risk_factor.Overweight = false;
		}

		getline(ss, val, ',');
		if (val == "T")
		{
			patientVector->at(i)->risk_factor.Alcoholic = true;
		}
		else if (val == "F")
		{
			patientVector->at(i)->risk_factor.Alcoholic = false;
		}

		getline(ss, val, ',');
		if (val == "T")
		{
			patientVector->at(i)->risk_factor.Smoking = true;
		}
		else if (val == "F")
		{
			patientVector->at(i)->risk_factor.Smoking = false;
		}

		getline(ss, val, ',');
		if (val == "T")
		{
			patientVector->at(i)->risk_factor.HRT = true;
		}
		else if (val == "F")
		{
			patientVector->at(i)->risk_factor.HRT = false;
		}

		i++;
	}
	fin.close();
}

//Desc: writes the patient data to a csv file
//Parms: vector of patient objects
//Return: n/a
inline void writeToCSV(std::vector<Patient*>* v)
{
	std::fstream fout;
	fout.open("Wisconsin data-results.csv", std::ios::out | std::ios::app);

	for (size_t i = 0; i < v->size(); i++)
	{
		fout << v->at(i)->clump_ << ",";
		fout << v->at(i)->cellSize_ << ",";
		fout << v->at(i)->cellShape_ << ",";
		fout << v->at(i)->mAdhesion_ << ",";
		fout << v->at(i)->seCellSize_ << ",";
		fout << v->at(i)->bareNuclei_ << ",";
		fout << v->at(i)->chromatin_ << ",";
		fout << v->at(i)->nucleoli_ << ",";
		fout << v->at(i)->mitosis_ << ",";
		fout << v->at(i)->diagnosis_ << std::endl;
	}
	std::cout << "Saving current PriorityMap to csv file" << std::endl;
	fout.close();
}

//Desc: writes the weight of the edges between risk factor vertices to a csv
//Parms: graph object
//Return: n/a
inline void writeBenignMatrix(Graph* g)
{
	std::fstream fout;
	fout.open("adjmatrixBenign.csv", std::ios::out | std::ios::app);

	for (size_t i = 0; i < 8; i++)
	{
		GraphNode* ptr = g->adjList_[i].head_;
		while (ptr != nullptr)
		{
			fout << ptr->weight_ << ",";
			ptr = ptr->next_;
		}
		fout << std::endl;
	}
	std::cout << "Saving current Benign Adjacency Matrix to csv file" << std::endl;
	fout.close();
}

//Desc: writes the weight of the edges between risk factor vertices to a csv
//Parms: graph object
//Return: n/a
inline void writeMalignantMatrix(Graph* g)
{
	std::fstream fout;
	fout.open("adjmatrixMalignant.csv", std::ios::out | std::ios::app);

	for (size_t i = 0; i < 8; i++)
	{
		GraphNode* ptr = g->adjList_[i].head_;
		while (ptr != nullptr)
		{
			fout << ptr->weight_ << ",";
			ptr = ptr->next_;
		}
		fout << std::endl;
	}
	std::cout << "Saving current Malignant Adjacency Matrix to csv file" << std::endl;
	fout.close();
}

//Desc: totals and prints out the number of patients
//Parms: vector of patients
//Return: n/a
inline void countPatients(std::vector<Patient*>* p) {
	int count = 0;
	for (unsigned long i = 0; i < p->size(); i++)
	{
		count++;
	}
	std::cout << "Number of patients is: " << count << std::endl;
}

//Desc: totals and prints out the number of patients who have benign tumours
//Parms: vector of patients
//Return: n/a
inline void countBenign(std::vector<Patient*>* p) {
	int count = 0;
	for (unsigned long i = 0; i < p->size(); i++)
	{
		if (p->at(i)->diagnosis_ == 2)
			count++;
	}
	std::cout << "Number of Benign patients is: " << count << std::endl;
}

//Desc: totals and prints out the number of patients who have malignant tumours
//Parms: vector of patients
//Return: n/a
inline void countMalignant(std::vector<Patient*>* p) {
	int count = 0;
	for (unsigned long i = 0; i < p->size(); i++)
	{
		if (p->at(i)->diagnosis_ == 4)
			count++;
	}
	std::cout << "Number of Malignant patients is: " << count << std::endl;
}