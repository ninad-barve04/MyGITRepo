
def sort(array):
    i = 0

    for i in range(1, len(array)):
        j = i
        while array[j-1] > array[j] and j > 0:
            array[j-1], array[j] = array[j], array[j-1]
            j = j - 1

    
    return array



# this does in 15 steps
def sort2(array):
    i = 0

    cnt =0;
    for i in range(0, len(array)):
       
        for j in range ( 0 , i):
            cnt = cnt+1;
            print(cnt, i, j, array)
            if( array[i] < array[j]):
                d = array[i];
                array[i] = array[j];
                array[j] =d;
            
        print('\n')


            
    
    return array


def selection(array):
    i = 0

    cnt =0;
    for i in range(0, len(array)):
       
        min = array[i];
        for j in range (i  , len(array)):
            cnt = cnt+1;
            print(cnt, i, j, array)
            if( min > array[j]):
                min = array[j];
                d = array[i];
                array[i] = array[j];
                array[j] =d;
            
        print('\n')


            
    
    return array

def bubblesort(array):
    i = 0

    cnt = 0;
    length = len(array)
    for i in range(0, length):
       
        min = array[i];
        for j in range ( 0  ,length - i -1 ):
            cnt = cnt+1;
            print(cnt, i, j, array)
            if( array[i] < array[j]):
                d = array[i];
                array[i] = array[j];
                array[j] =d;
            
        print('\n')


            
    
    return array


array = [10, 5, 22, 3, 17, 10]
# sorted = selection(array)
# print(sorted)
# sorted  = selection2(array)
# print(sorted)

sorted = selection( array);
print(sorted)