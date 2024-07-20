### 70分

    - 用BFS搜尋，以任何non-leaf node為端點的路徑(B--C--D)，必可找到一條比他長的路徑(A--B--C--D)，因此不用triverse過每個node，只需要對leaf node做BFS即可
        
### 滿分解

    - 透過觀察可以發現，設離leaf node A最遠的leaf node是B，若由B開始做BFS，其距離必 >= 從A開始做。
    - 因此不需要對每個leaf node都做BFS，只需要先從任意一個leaf node做，再由最遠的leaf node做，重複此過程直到2次BFS所得的distance相等即可。