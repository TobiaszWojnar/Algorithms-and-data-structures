package l2;

public class SortAlg {

    public static void insertS (int[] table, String comp) {
        int key;
        int j;
        if (comp.equals("<=")) {
            for (int i = 1; i < table.length; i++) {
                key = table[i];
                for (j = i - 1; j >= 0 && table[j] > key; j--) {
                    table[j + 1] = table[j];
                }
                table[j + 1] = key;
            }
        } else {
            for (int i = 1; i < table.length; i++) {
                key = table[i];
                for (j = i - 1; j >= 0 && table[j] < key; j--) {
                    table[j + 1] = table[j];
                }
                table[j + 1] = key;
            }
        }
    }

    public static void mergeS (int[] table, String comp){
        if (table.length < 2) {
            return;
        }
        int mid = table.length/2;
        int[] l = new int [mid];
        int[] r = new int [table.length-(mid)];
        for (int i=0; i < mid; i++){
            l[i] = table[i];
        }
        for(int i = mid; i < table.length; i++){
            r[i-mid] = table[i];
        }
        mergeS(l,comp);
        mergeS(r,comp);

        merge (table,l,r,mid,table.length-mid,comp);

    }
    public static void merge(int[] table, int[] l, int[] r, int left, int right,String comp){
        int i=0;
        int j=0;
        int k=0;
        if(comp.equals("<=")) {
            while (i < left && j < right) {
                if (l[i] <= r[j]) {
                    table[k++] = l[i++];
                } else {
                    table[k++] = r[j++];
                }
            }
        } else {
            while (i < left && j < right) {
                if (l[i] >= r[j]) {
                    table[k++] = l[i++];
                } else {
                    table[k++] = r[j++];
                }
            }
        }
        while (i < left) {
            table[k++] = l[i++];
        }
        while (j < right) {
            table[k++] = r[j++];
        }
    }
    public static void quickS (int[] table, int low, int high, String comp){
        if (low < high)
        {
            int pi = partition(table, low, high,comp);
            quickS(table, low, pi-1, comp);
            quickS(table, pi+1, high, comp);
        }
    }

    static int partition(int table[], int low, int high,String comp)
    {
        int pivot = table[high];
        int i = (low-1);
        if(comp.equals("<=")){
            for (int j = low; j < high; j++) {
                if (table[j] < pivot) {
                    i++;

                    int temp = table[i];
                    table[i] = table[j];
                    table[j] = temp;
                }
            }
        }else {
            for (int j = low; j < high; j++) {
                if (table[j] > pivot) {
                    i++;

                    int temp = table[i];
                    table[i] = table[j];
                    table[j] = temp;
                }
            }
        }
        int temp = table[i+1];
        table[i+1] = table[high];
        table[high] = temp;

        return i+1;
    }

    public static int[] dualPivotS (int[] table, String comp){
        return table;
    }
    public static int[] randixS (int[] table, String comp){
        return table;
    }
    public static void printTabInLine (int[] table){
        String tabInLine="";
        for(int i=0; i<table.length;i++){
            tabInLine += Integer.toString(table[i]);
            tabInLine += " ";
        }
        System.out.println(tabInLine);
    }
}
