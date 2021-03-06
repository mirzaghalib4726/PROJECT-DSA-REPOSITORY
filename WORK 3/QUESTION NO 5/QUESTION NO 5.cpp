//AS ALREADY MENTIONED, THE LINKED LIST HAVE ODD NUMBER OF NODES.
//ONLY HEAD NODE IS PRESENT

//                                                                STEPS

//1. WE WILL CREATE 2 NODES(F_NODE, S_NODE) BOTH POINTING TO HEAD OF LINKED LIST.
//2. WE WILL USE A WHILE LOOP FOR TRANSVERSAL OF LINKED LIST.
//3. THE LOOP WILL BREAK WHEN(F_NODE->NEXT == NULLPTR || F_NODE->NEXT->NEXT == NULLPTR).
//4. ON EACH ITERATION, THE S_NODE WILL POINT TO S_NODE->NEXT AND F_NODE TO F_NODE->NEXT->NEXT.
//5. WHEN THE LOOP WILL BREAK SO S_NODE WILL BE POINTING TO THE MID OF THE LINKED LIST