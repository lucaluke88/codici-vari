#ifndef STRUTTURE_H
#define STRUTTURE_H

// Inclusioni di sistema
#include <algorithm>
#include <boost/cstdlib.hpp>
#include <boost/iterator/counting_iterator.hpp>
#include <boost/iterator/indirect_iterator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>
#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <math.h>
#include <random>
#include <sstream>
#include <stdio.h>
#include <string>
#include <thread>
#include <vector>

// Namespace e alias per i tipi
using namespace std;
typedef vector<uint16_t> vectorUint;
typedef vector<double> vectorDouble;
typedef vector<string> vectorString;
typedef vector< vector<uint16_t> > matrixUint;
typedef vector< vector<double> > matrixDouble;

//! Valori di default per CVRP
struct AcoVariabiliType
{
	uint16_t minRichiesta = 1;
	uint16_t maxRichiesta = 100;
	uint16_t minPeso = 1;
	uint16_t maxPeso = 100;
	uint16_t nVertici = 10;
	uint16_t nAnt = 10;
	uint16_t capacita = 0;
    double feromoneIniziale = pow(10,-6);
    double feromoneMassimo = 1;
    bool verbose = 0;
    bool grafoFile = 0;

    uint16_t Q = 2; //deposition costant
	double temperatura = 100;
	double alfa = 2;	// rilevanza del feromone
	double beta = 1;	// rilevanza della distanza
	uint16_t d = 1; // numero di best ant che possono depositare nella global update
	uint16_t f = 2;	// parametro di Savings
	uint16_t g = 2;	// parametro di Savings
	uint16_t e = 0; // numero di soluzioni preservate per elitismo
	double lambda = 0.5;	// rilevanza dell'euristica di Savings
	double rho = 0.1; // evaporation rate
	double qzero = 75;	// (0.75) Probabilità che una ant scelga in maniera deterministica il prossimo vertice (exploitation vs exploration)
	double theta = 0.9; // local decay rate

	uint16_t maxGenerazioni = 1000;
	uint16_t tentativiMiglioramento = 20;
	uint16_t sizeMetaPopolazione = 6;
	bool useMultiThread = 0; //usa il multithread
	bool useLocalSearch = 1; // usa la ricerca locale
	bool showTours = 1;
} ACOVARS;

struct desiderabilitaType
{
    uint16_t vertice;
    double value;
};

struct AntType
{
	vectorUint tour;
	vectorUint flagVerticiVisitati;
	vector<desiderabilitaType> desiderabilitaVertici;
	vectorUint vertici_visitati;
	uint16_t caricoCorrente = 0;
};
#endif // STRUTTURE_H
