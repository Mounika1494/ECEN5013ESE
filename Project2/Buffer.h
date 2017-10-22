
#ifndef SOURCES_BUFFER_H_
#define SOURCES_BUFFER_H_
#include<stdio.h>
#include<stdint.h>

/********************************************************************************
 * Copyright (C) 2017 by Mounika Reddy Edula
 *
 * Redistribution,modification or use of this software in source or binary is permitted as
 * long as the files maintain this copyright.Mounika Reddy Edula is not liable for any
 * misuse of this materials
 *
 * ****************************************************************************/
/*struct for circular Buffer*/
typedef struct
{
uint8_t* HEAD;
uint8_t* TAIL;
uint8_t* Buffer;
}structure;

char *d;
char *s;

/*enum for status of function*/
enum BUFFER_STATE {BUFFER_FULL,BUFFER_EMPTY};

/*************************************************************
 * @brief add data to the circular Buffer
 *
 * @param s      Buffer structure
 *        value  uint8_t added item
 *        length uint8_t length of the buffer
 * @return 
 *       Status enum Buffer_state
 *************************************************************/
uint8_t add_data(structure *s,uint8_t Value,uint8_t length);

/**************************************************************
 * @brief to check if buffer is full
 *
 * @param s      Buffer Structure
 *        length length of buffer
 * @return
 *        Status enum BUFFER_STATE
 **************************************************************/        
uint8_t Buffer_Full(structure *s,uint8_t length);

/**************************************************************
 * @brief to check if buffer is empty
 *
 * @param  s Buffer Structure
 *
 * @return 
 *        Status enum BUFFER_STATE
 *
 ***************************************************************/        
uint8_t Buffer_Empty(structure *s);

/***************************************************************
 * @brief to remove data from buffer
 *
 * @param s Buffer Structure
 *
 * @return 
 *       Status enum Buffer_STATE
 ****************************************************************/       
uint8_t remove_data(structure *s);

/****************************************************************
 * @brief to read circular buffer
 *
 * @param s Buffer Structure
 *
 * @return 
 *       status enum BUFFER_STATE
 *
 ****************************************************************/       
uint8_t get_data(structure *s);

/****************************************************************
 * @brief to initialise(allocation of memory)
 *
 * @param void
 *
 * @return void
 * *************************************************************/
void Buffer_init();

/***************************************************************
 * @brief to release the memory
 *
 * @return 
 *       void
 *
 * ************************************************************/      
void release(char *s);

#endif /* SOURCES_BUFFER_H_ */
