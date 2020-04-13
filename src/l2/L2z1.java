package l2;

public class L2z1 {
    public static void main(String[] args) {
        try {
            String type = GetData.hasValidArgs(args)[0];
            String comp = GetData.hasValidArgs(args)[1];

            int[] table = GetData.getTable();
                switch (type){
                    case "insert":
                        SortAlg.insertS(table, comp);
                        break;
                    case "merge":
                        SortAlg.mergeS(table, comp);
                        break;
                    case "quick":
                        SortAlg.quickS(table,0,table.length-1, comp);
                        break;
                    case "dualPivot":
                        SortAlg.dualPivotS(table, comp);
                        break;
                    case "randix":
                        SortAlg.randixS(table, comp);
                        break;
                    default:
                        return;
                }
                SortAlg.printTabInLine(table);
        } catch (Exception e){
            System.out.println(e.getMessage());
        }
    }

}