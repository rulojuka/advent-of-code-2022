import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Collection;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.StringTokenizer;

public class Filesystem {
    public static void main(String[] args) {
        Node root = new Node(null,"/");
        parseCommands(root);
        Collection<Node> allNodes = getAllNodes(root);
        
        // Problem 1
        final Long magicNumberProblemOne = 100000L;
        Long sum = allNodes.stream()
            .filter(node -> (!node.isFile() && node.getSize() <= magicNumberProblemOne))
            .map(node -> node.getSize())
            .reduce(0L, Long::sum);
        System.out.println(sum);
        
        // Problem 2
        final Long totalSpace = 70000000L;
        final Long spaceNeeded = 30000000L;
        Long freeSpace = totalSpace - root.getSize();
        Long minimumSizeToFree = spaceNeeded - freeSpace;
        Long response = allNodes.stream()
            .filter(node -> (!node.isFile() && node.getSize() > minimumSizeToFree))
            .sorted()
            .findFirst().orElseThrow()
            .getSize();
        System.out.println(response);
    }

    public static void parseCommands(Node root){
        Node currentDirectory = root;
        FastScanner sc = new FastScanner();
        String next = sc.nextToken();
        String command = "";
        String directory = "";
        String name = "";
        Long size;
        Boolean finished = false;
        try{
            while(!finished){
                command = sc.nextToken();
                if(command.charAt(0)=='c'){ // cd command
                    directory = sc.nextToken();
                    if("/".equals(directory)){
                        currentDirectory = root;
                    }else if("..".equals(directory)){
                        currentDirectory = currentDirectory.getParent();
                    } else {
                        currentDirectory = currentDirectory.getChild(directory);
                    }
                    next = sc.nextToken();
                } else { // ls command
                    while(true){
                        next = sc.nextToken();
                        if(next == null){ // file finished
                            finished = true;
                            break;
                        }
                        else if("$".equals(next)){ // go to next command
                            break;
                        }else if(next.charAt(0)=='d'){ // directory
                            name = sc.nextToken();
                            currentDirectory.addChild(name);
                        } else{ // file
                            size = Long.parseLong(next);
                            name = sc.nextToken();
                            currentDirectory.addChild(name,size);
                        }
                    }
                }
            }
        }catch(Exception e){
            // EOF
        }
    }

    public static Collection<Node> getAllNodes(Node root){
        Collection<Node> set = new HashSet<Node>();
        Deque<Node> stack = new ArrayDeque<Node>();
        stack.push(root);
        while(!stack.isEmpty()){
            Node current = stack.pop();
            set.add(current);
            stack.addAll(current.getChildren());
        }
        return set;
    }

    public static class Node implements Comparable<Node>{
        private Node parent;
        private Map<String,Node> children;
        private Long size;

        public Node(Node parent, String name){
            this.parent = parent;
            children = new HashMap<String,Node>();
            size = null;
        }
    
        public Long getSize(){
            if(this.size==null){
                this.size = children.values().stream()
                    .map(node->node.getSize())
                    .reduce(0L, Long::sum);
            }
            return this.size;
        }

        public void setSize(Long size){
            this.size = size;
        }
    
        public void addChild(String name){
            this.addChild(name, null);
        }

        public void addChild(String name, Long size){
            Node newNode = new Node(this,name);
            newNode.setSize(size);
            children.put(name,newNode);
        }
    
        public Node getChild(String name){
            return this.children.get(name);
        }

        public Collection<Node> getChildren(){
            return this.children.values();
        }

        public Node getParent(){
            return this.parent;
        }

        public Boolean isFile(){
            return this.children.isEmpty();
        }

        public int compareTo(Node otherNode){
            return (this.getSize() - otherNode.getSize()) > 0 ? 1 : -1;
        }

    }

    public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
 
		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
 
		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(nextToken());
		}
 
		long nextLong() {
			return Long.parseLong(nextToken());
		}
 
		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}
}