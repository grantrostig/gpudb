#ifndef __SSB_HASHJOIN__
#define __SSB_HASHJOIN__

#include "common.h"

struct joinNode{
	int totalAttr;			// the toal number of attributes generated by the join
	int tupleSize;			// the size of the tuple in the join result
	struct tableNode *leftTable;	// the fact table
	struct tableNode *rightTable;	// the dimension table
	
	int leftKeyIndex;		// the index of factable's join key
	int rightKeyIndex;		// the index of dimension table's join key 

	int leftOutputAttrNum;		// the number of output attributes from the fact table
	int * leftOutputIndex;		// the index of the output attributes from the fact table
	int * leftOutputAttrType;	// the type of the output attributes from the fact table
	int * leftPos;			// the final position of the output attributes from the fact table

	int rightOutputAttrNum;		// the number of output attributes from the dimension table
	int * rightOutputIndex;		// the index of the output attributes from the dimension table
	int * rightOutputAttrType;	// the type of the output attributes from the dimension table
	int * rightPos;			// the final position of the output attributes from the dimenstion table

	int * keepInGpu;		// whether the result should be kept in GPU global memory or not.
					// 1 doesn't imply that the data will be 100% in the GPU. 
					// it may still be in CPU memory if the original data is not loaded into GPU
};


#endif
