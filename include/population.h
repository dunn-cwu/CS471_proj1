/**
 * @file population.h
 * @author Andrew Dunn (Andrew.Dunn@cwu.edu)
 * @brief Header file for the Population class.
 * Stores a population and fitness values.
 * Includes functions to analyze the fitness data.
 * @version 0.1
 * @date 2019-04-04
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __POPULATION_H
#define __POPULATION_H

#include <cstddef> // size_t definition
#include <random>
#include <ostream>

namespace mdata
{
    /**
     * @brief Data class for storing a multi-dimensional population of data.
     * Includes fitness analysis functions.
     * 
     * @tparam T Data type of the population.
     */
    template<class T>
    class Population
    {
    public:
        Population(size_t popSize, size_t dimensions);
        ~Population();

        bool isReady();
        size_t getPopulationSize();
        size_t getDimensionsSize();
        T* getPopulation(size_t popIndex);

        bool generate(T minBound, T maxBound);
        bool setFitness(size_t popIndex, T value);
        T getFitnessValue(size_t popIndex);
        T getFitnessAverage();
        T getFitnessStandardDev();
        T getFitnessRange();
        T getFitnessMedian();

        void outputPopulation(std::ostream& outStream, const char* delim, const char* lineBreak);
        void outputFitness(std::ostream& outStream, const char* delim, const char* lineBreak);
    protected:
        const size_t popSize; /** Size of the population, and the number of rows in the popMatrix */
        const size_t popDim;  /** Dimensions of the population, and the number of columns in the popMatrix */
        T** popMatrix; /** Matrix of population values */
        T* popFitness; /** Array of fitness values */

        std::random_device rdev; /** Random seed for random number generator */
        std::mt19937 rgen; /** Mersenne twister random number generator engine */

        bool allocPopMatrix();
        void releasePopMatrix();

        bool allocPopFitness();
        void releasePopFitness();
    };
}

#endif

// =========================
// End of population.h
// =========================
