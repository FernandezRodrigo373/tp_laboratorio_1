int controller_loadFromText(char* path , LinkedList* pArrayListCars);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListAuto(LinkedList* pArrayListCars);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_ListAuto(LinkedList* pArrayListAutos);
int controller_NewListAnio(void* unAuto);
LinkedList* controller_backUp(LinkedList* this);
int controller_clearLinkedList(LinkedList* this);
int controller_editAuto(LinkedList* pArrayListAuto);
int controller_removeAuto(LinkedList* pArrayListAuto);

int controller_sortAuto(LinkedList* pArrayListAuto);
int controller_addAuto(LinkedList* pArrayListAutos);
