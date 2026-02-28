#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// TODO: Declare 2 initialized global variables (DATA segment)
int intializedglobalVar = 50;
int intializedglobalVar2 = 100;

// TODO: Declare 2 uninitialized global variables (BSS segment)
int unintializedglobalVar;
int unintializedglobalVar2;


// Stack check function: receives address from caller (parent frame)
// and compares with a local variable (child frame)
void checkStack(int* parentAddr) {
    int childVar = 0;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;
    printf("Address of parentAddr: %p\n", (void*)parentAddr);
    printf("Address of &parentAddr: %p\n", (void*)&parentAddr);
    printf("Address of childVar: %p\n", (void*)&childVar);
    printf("Stack grows: %s\n", parentAddr > &childVar ? "DOWN" : "UP");
    // TODO: Print parentAddr value (points to main's local var - parent frame)
    // TODO: Print &parentAddr (parameter's own address - child frame)
    // TODO: Print &childVar (local var address - child frame)
    // TODO: Print "Stack grows: DOWN" or "UP" based on comparison
    //       Compare: parentAddr > &childVar ? "DOWN" : "UP"
    //       (parent frame address vs child frame address)
    cout << endl;
}

int main() {

    // TODO: Declare a local variable (STACK - will be passed to checkStack)
    int localVar = 10; // Idk how much to intialize with or the other two to be honest
    checkStack(&localVar);

    // TODO: Allocate 2 heap variables using malloc (use larger sizes, e.g. 1024)
    //       Note: new may not allocate sequentially; malloc with larger sizes
    //       is more reliable for demonstrating heap growth direction
    char* heapVar1 = (char*)malloc(1024); // from assignment
    char* heapVar2 = (char*)new int;
    cout << "Address of heapVar1: " << (void*)heapVar1 << endl;
    cout << "Address of heapVar2: " << (void*)heapVar2 << endl;

    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;

    // TODO: Print TEXT segment - 2 function addresses
    //       e.g., (void*)&main and (void*)&checkStack
    cout << "Address of main(): " << (void*)&main << endl; // from assignment except rewrote the printAddress to checkstack
    cout << "Address of checkStack(): " << (void*)&checkStack << endl;

    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    // ...
    cout << endl;

    // TODO: Print DATA segment - 2 initialized global addresses + values
    cout << "Address of intializedglobalVar: " << (void*)&intializedglobalVar << endl;
    cout << "Value of intializedglobalVar: " << intializedglobalVar << endl;
    cout << "Address of intializedglobalVar2: " << (void*)&intializedglobalVar2 << endl;
    cout << "Value of intializedglobalVar2: " << intializedglobalVar2 << endl;

    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    // ...
    cout << endl;

    // TODO: Print BSS segment - 2 uninitialized global addresses + values
    cout << "Address of unintializedglobalVar: " << (void*)&unintializedglobalVar << endl;
    cout << "Value of unintializedglobalVar: " << unintializedglobalVar << endl;
    cout << "Address of unintializedglobalVar2: " << (void*)&unintializedglobalVar2 << endl;
    cout << "Value of unintializedglobalVar2: " << unintializedglobalVar2 << endl;


    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;
    // ...
    cout << endl;

    // STACK: call checkStack with address of your local variable
    // TODO: checkStack(&yourLocalVar);
    checkStack(&localVar);

    // TODO: Print HEAP segment - 2 heap addresses + comparison
    //       Print "Heap grows: UP" or "DOWN"
    cout << "Address of heapVar1: " << (void*)heapVar1 << endl;
    cout << "Address of heapVar2: " << (void*)heapVar2 << endl;
    cout << "Heap grows: " << (heapVar2 > heapVar1 ? "UP" : "DOWN") << endl;


    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;
    cout << endl;

    // TODO: Print relative position summary
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;
    // ...

    // TODO: Free all heap allocations

    return 0;
}

/*
 * EXPERIMENTAL RESULTS:
 * TODO: After running your program, explain what you observed:
 * - Which segment has the lowest addresses?
 * The lowest address was the Text I think because its one of 0x5s and the 
 * others are 0x7s but it also has the smalles number compare to the other 0x5s
 * - Which has the highest?
 * The highest was the heap because it had the largest number in the 0x7s
 * - Does stack grow down? How did you verify this?
 * The stack grows down according to the code meaning that the parent address if bigger then the child address 
 * - Does heap grow up? How did you verify this?
 * The heap grows up according to the code meaning that the second heap variable address is bigger then the first heap variable address
 * - What is the gap between HEAP and STACK?
 * The gap between the heap and stack is the difference between the second heap variable address and the child variable address in the stack. 
 * This can be calculated by subtracting the child variable address from the second heap variable address.
 */
