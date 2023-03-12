/**
 * \file fifo.h
 * \author Ines Leite
 * \date March 12,2023
 */


#ifndef FIFO_H
#define FIFO_H

/**
 * Fifo structure
 */
struct FIFO{
	int size;	/**< Size of the fifo*/
	int* values;/**< Array of stored values in fifo*/
	int tail; 	/**< Position of newest fifo value */
	int head;	/**< Position of oldest fifo value */
	};

/**
 * \brief Fifo initialization function
 * 
 * Intializes values vector with dinamic memory, initializes head and tail
 * to 0 and size with fifo desired size;
 * Maximum Size value is 10
 * 
 * \param fifo structure address
 * \param size size of fifo
 * \returns 0: OK ; -1: Error 
 */
int MyFIFOInit(struct FIFO* fifo, int size);

/**
 * \brief Incert function new value to fifo queue
 * 
 * \param fifo structure address
 * \param val val to be inserted in the fifo
 */

int MyFIFOInsert(struct FIFO* fifo, int val);

/**
 * \brief Remove function oldest value from queue
 * 
 * 
 * \param fifo structure address
 */

int MyFIFORemove(struct FIFO* fifo);

/**
 * \brief Show oldest value in the fifo
 *
 * \param fifo structure address
 * \returns oldest value in the fifo
 */
int MyFIFOPeep(struct FIFO* fifo);

/**
 * \brief Fifo queue size
 * 
 * Returns how many values are being stored
 * 
 * \param fifo fifo structure address
 * \returns fifo size
 */
int MyFIFOSize(struct FIFO* fifo);


#endif
