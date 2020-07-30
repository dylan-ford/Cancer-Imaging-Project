#include "BinaryTree.hpp"
#include "Node.hpp"
#include "ExtraFunctions.hpp"
#include "Graph.hpp"
//#include <crtdbg.h>
//#define _CRTDBG_MAP_ALLOC

using namespace std;

int main() {
//#if defined(_DEBUG)
//	int dbgFlags = ::_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
//
//	dbgFlags != _CRTDBG_CHECK_ALWAYS_DF;
//
//	dbgFlags != _CRTDBG_DELAY_FREE_MEM_DF;
//
//	dbgFlags != _CRTDBG_LEAK_CHECK_DF;
//
//	_CrtSetDbgFlag(dbgFlags);
//#endif

	BinaryTree* bTree = new BinaryTree();
	
	vector<Patient*>* patientVector = new vector<Patient*>();
	
	readInCSV(patientVector);

	for (size_t i = 0; i < patientVector->size(); i++)
	{
		patientVector->at(i)->traverse(bTree->root_);
	}
	
	writeToCSV(patientVector);	
	countPatients(patientVector);
	countBenign(patientVector);
	countMalignant(patientVector);

	////GRAPHS
	readInRF(patientVector);
	Graph* bGraph = new Graph(8);
	Graph* mGraph = new Graph(8);

	//create adjacency matrices
	for (size_t i = 0; i < patientVector->size(); i++)
	{		
		vector<bool>* patientRisks = new vector<bool>();
		patientRisks->push_back(patientVector->at(i)->risk_factor.Gender);
		patientRisks->push_back(patientVector->at(i)->risk_factor.Age);
		patientRisks->push_back(patientVector->at(i)->risk_factor.GeneticFactor);
		patientRisks->push_back(patientVector->at(i)->risk_factor.FamilyHistory);
		patientRisks->push_back(patientVector->at(i)->risk_factor.Overweight);
		patientRisks->push_back(patientVector->at(i)->risk_factor.Alcoholic);
		patientRisks->push_back(patientVector->at(i)->risk_factor.Smoking);
		patientRisks->push_back(patientVector->at(i)->risk_factor.HRT);

		for (size_t j = 0; j < patientRisks->size(); j++)
		{
			for (size_t k = j; k < patientRisks->size(); k++)
			{
				if (k != j)
				{
					if (patientRisks->at(j) && patientRisks->at(k))
					{
						if (patientVector->at(i)->diagnosis_ == 2)
						{
							bGraph->incrementEdge(j, k);
						}
						else
							mGraph->incrementEdge(j, k);
					}
				}
			}
		}
		delete patientRisks;
	}

	cout << endl;
	cout << "Benign" << endl;
	bGraph->printGraph();

	cout << endl;

	cout << "Malignant" << endl;
	mGraph->printGraph();

	cout << endl;

	writeBenignMatrix(bGraph);
	writeMalignantMatrix(mGraph);

	//destruct binary tree
	delete bTree;

	////delete vectors
	for (size_t i = 0; i < patientVector->size(); i++)
	{
		delete patientVector->at(i);
	}
	delete patientVector;

	////destruct graphs
	delete bGraph;
	delete mGraph;

	//_CrtDumpMemoryLeaks();
}
