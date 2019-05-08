//// KNAPSACK
//// ITERATE THROUGH # OF OBJECTS and WEIGHT++
//// THE FORMULA visually makes a lot of sense
//
//// FIRST CREATE BAG OJECT TO CARRY PRICE AND WEIGHT
//struct BagObject {
//	int price;
//	int weight;
//};
//
//const int capacity = 9; // MEANS 8
//const int num_of_objects = 4;
//
//int matrix[num_of_objects + 1][capacity + 1]; // 1 more for the weird indexing 0s issue
//
//void knapsack() {
//	// SEED objects
//	BagObject one = { 1, 2 };
//	BagObject two = { 2, 3 };
//	BagObject three = { 5, 4 };
//	BagObject four = { 6, 5 };
//	std::vector<BagObject> objects = { one, two, three, four };
//
//	// DOUBLE loops (which dictates the MxN run time)
//	for (int i = 0; i < num_of_objects; ++i) {
//		for (int w = 0; w < capacity; ++w) {
//			if (objects[i].weight <= w) { // if current object fits in the WEIGHT being processed
//										  // compare
//				int first = matrix[i][w + 1]; // MAX PRICE from previous row
//				int second = matrix[i][w + 1 - objects[i].weight] + objects[i].price; // PRICE if we put this OBJECT there instead
//																					  // set matrix value on the max of these
//				matrix[i + 1][w + 1] = std::max(first, second);
//			}
//			else { // Object can't fit
//				   // just carry the values over for future processing
//				matrix[i + 1][w + 1] = matrix[i][w + 1];
//			}
//		}
//	}
//}

//===================================
//===================================
// ANOTHER PSEUDOCODE
//===================================
//===================================
// INIT()

// STRUCT - price | weight

// init capacity and numObjects

// init matrix [capacity][numObjects]

//===================================
// Main function
// CREATE STRUCT OBJECTS with price | weight
// add them to a vector

// DOUBLE LOOPS
// numObjects++
//		capacity++

		// if current object fits in the WEIGHT being processed
//		if (objects[i].weight <= w) {
			//compare
			// MAX PRICE from previous row
			//int first = matrix[i][w + 1]; 

			// PRICE if we put this OBJECT there instead
			//int second = matrix[i][w + 1 - objects[i].weight] + objects[i].price; 

			// set matrix value on the max of these
			//matrix[i + 1][w + 1] = std::max(first, second);
		//}	else {
			// object can't fit
			//just carry the values over for future processing
			//matrix[i + 1][w + 1] = matrix[i][w + 1];
		//}
//return matrix[4][9];
