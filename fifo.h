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
    int count; /**< Number of stored values at a given time */
	};
	
/**
 * \Brief Fifo error/warning flags 
 * 
 */
typedef enum{ ERR_FIFO = -1,/**<allocation error*/
			  OK,			/**< OK*/
			  ERR_SIZE,		/**<Expect size out of limits*/
			  FULL_FIFO,	/**<Fifo is full*/
			  EMPTY_FIFO,	/**<Fifo is empty*/
			  ERR_INIT}FifoErr_t;
	
/**
 * \brief Fifo initialization function
 * 
 * Intializes values vector with dinamic memory, initializes head, tail and counter
 * to 0 and size with fifo desired size;
 * Maximum Size value is 10
 * 
 * \param fifo structure address
 * \param size size of fifo
 * \returns 0: OK ; 1 ERR_FIFO: Error fifo size; -1 ERR_FIFO: mem error
 */
int MyFIFOInit(struct FIFO* fifo, int size);

/**
 * \brief Incert function new value to fifo queue
 * 
 * \param fifo structure address
 * \param val val to be inserted in the fifo
 * \return 0: OK; 2 FULL_FIFO: error fifo full
 */

int MyFIFOInsert(struct FIFO* fifo, int val);

/**
 * \brief Remove function oldest value from queue
 * 
 * Prints value removed
 *
 * \param fifo structure address
 * \return 0: OK; 3 EMPTY_FIFO: error fifo empty
 */

int MyFIFORemove(struct FIFO* fifo);

/**
 * \brief Prints oldest value in the fifo
 *
 * \param fifo structure address
 * \returns 0: OK; 3 EMPTY_FIFO: error fifo empty
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

/**
 * \brief Fifo resize
 * 
 * Resize fifo dinamically, trucates if shorter
 * 
 * \param fifo fifo structure address
 * \param newsize new fifo size
 * \returns 0: OK ; 1 ERR_FIFO: Error fifo size; -1 ERR_FIFO: mem error
 */
int MyFIFOResize(struct FIFO* fifo, int newsize);

/**
 * \brief Fifo destruction
 * 
 * Free memory and values point to NULL
 * 
 * \param fifo fifo structure address
 */
void MyFIFOEnd(struct FIFO* fifo);


#endif
