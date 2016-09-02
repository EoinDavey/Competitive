import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
/*
ID: eoin.da1
LANG: JAVA
PROG: castle
 */

class castle {
	PrintWriter out;
	int N,M,numRooms, currentRoomSize,maxRoomSize, maxNewRoomSize;
	Room[][] castle;
	int[] roomSizes,wallPos;
	
	public static void main(String[] args) throws IOException{
		castle main = new castle();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		genEdges();
		countRooms();
		genPotentials();
		findBestWall();
		printResult();
	}
	
	private void findBestWall() {
		int potI,potJ,maxPotential;
		wallPos = new int[2];
		maxPotential=potI=potJ= 0;
		for(int i = 0; i < castle.length;i++){
			for(int j = 0; j< castle[i].length;j++){
				if(castle[i][j].potential > maxPotential){ 
					maxPotential = castle[i][j].potential;
					potI = i;
					potJ = j;
				} else if(castle[i][j].potential == maxPotential){
					if(j<potJ){
						potI = i;
						potJ = j;
					} else if(j==potJ){
						if(i > potI){
							potI = i;
							potJ = j;
						}
					}
				}
			}
		}
		maxNewRoomSize = maxPotential;
		wallPos[0] = potI; wallPos[1] = potJ;
	}

	private void genPotentials(){
		for(int i = 0; i < castle.length; i++){
			for(int j = 0; j < castle[i].length;j++){
				Room current;
				Room neighbour;
				current = castle[i][j];
				//north
				if(i>0){
					neighbour = castle[i-1][j];
					if(current.room != neighbour.room){
						current.potential = roomSizes[current.room] + roomSizes[neighbour.room];
					}
				}
				//east
				if(j<castle[i].length-1){
					neighbour = castle[i][j+1];
					if(current.room!=neighbour.room){
						current.potential = Math.max(roomSizes[current.room] + roomSizes[neighbour.room], current.potential);
					}
				}
			}
		}
	}

	private void countRooms() {
		numRooms=0;
		ArrayList<Integer> roomSizes= new ArrayList<Integer>();
		roomSizes.add(0);
		for(int i = 0; i<castle.length; i++){
			for(int j = 0; j<castle[i].length;j++){
				if(!castle[i][j].visited){
					currentRoomSize = 0;
					roomSizes.add(0);
					numRooms++;
					visit(castle[i][j]);
					roomSizes.set(numRooms, currentRoomSize);
					if(currentRoomSize > maxRoomSize) maxRoomSize = currentRoomSize;
				}
			}
		}
		this.roomSizes = new int[roomSizes.size()];
		for(int i = 1; i < roomSizes.size(); i++){
			this.roomSizes[i] = roomSizes.get(i);
		}
	}

	private void visit(Room r) {
		if(r.visited) return;
		currentRoomSize++;
		r.room = numRooms;
		r.visited = true;
		if(r.north!=null){
			visit(r.north);
		}
		if(r.west!=null){
			visit(r.west);
		}
		if(r.east!=null){
			visit(r.east);
		}
		if(r.south!=null){
			visit(r.south);
		}
	}

	void genEdges(){
		for(int i = 0; i < castle.length; i++){
			for(int j = 0; j< castle[i].length;j++){
				genConnections(i, j);
			}
		}
	}

	private void genConnections(int i, int j) {
		switch(castle[i][j].connections){
		case 1:
			//west
			castle[i][j].north = castle[i-1][j];
			castle[i][j].south = castle[i+1][j];
			castle[i][j].east = castle[i][j+1];
			break;
		case 2:
			//north
			castle[i][j].west = castle[i][j-1];
			castle[i][j].south = castle[i+1][j];
			castle[i][j].east = castle[i][j+1];
			break;
		case 3:
			//north & west
			castle[i][j].south = castle[i+1][j];
			castle[i][j].east = castle[i][j+1];
			break;
		case 4:
			//east
			castle[i][j].west = castle[i][j-1];
			castle[i][j].south = castle[i+1][j];
			castle[i][j].north = castle[i-1][j];
			break;
		case 5:
			//east & west
			castle[i][j].south = castle[i+1][j];
			castle[i][j].north = castle[i-1][j];
			break;
		case 6:
			//north & east
			castle[i][j].south = castle[i+1][j];
			castle[i][j].west = castle[i][j-1];
			break;
		case 7:
			//north, east & west
			castle[i][j].south = castle[i+1][j];
			break;
		case 8:
			//south
			castle[i][j].west = castle[i][j-1];
			castle[i][j].north = castle[i-1][j];
			castle[i][j].east = castle[i][j+1];
			break;
		case 9:
			//south & west
			castle[i][j].north = castle[i-1][j];
			castle[i][j].east = castle[i][j+1];
			break;
		case 10:
			//north & south
			castle[i][j].east = castle[i][j+1];
			castle[i][j].west = castle[i][j-1];
			break;
		case 11:
			//north, west & south
			castle[i][j].east = castle[i][j+1];
			break;
		case 12:
			//east & south
			castle[i][j].west = castle[i][j-1];
			castle[i][j].north = castle[i-1][j];
			break;
		case 13:
			//west, south and east
			castle[i][j].north = castle[i-1][j];
			break;
		case 14:
			//north, east & south
			castle[i][j].west = castle[i][j-1];
			break;
		case 0:
			//none
			castle[i][j].south = castle[i+1][j];
			castle[i][j].north = castle[i-1][j];
			castle[i][j].east = castle[i][j+1];
			castle[i][j].west = castle[i][j-1];
			break;
		}
	}
	
	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("castle.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("castle.out")));
		StringTokenizer st = new StringTokenizer(reader.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		castle = new Room[N][M];
		for(int i = 0; i < N; i++){
			st = new StringTokenizer(reader.readLine());
			for(int j = 0; j<M;j++){
				castle[i][j] = new Room(Integer.parseInt(st.nextToken()));
			}
		}
		reader.close();
	}
	
	private void printResult(){
		out.println(numRooms);
		out.println(maxRoomSize);
		out.println(maxNewRoomSize);
		out.print((wallPos[0]+1) + " " + (wallPos[1] + 1) + " ");
		if(wallPos[0] > 0){
			if(castle[wallPos[0]][wallPos[1]].room == castle[wallPos[0]-1][wallPos[1]].room){
				out.println("E");
				out.close();
				System.exit(0);
			}
			if(maxNewRoomSize - roomSizes[castle[wallPos[0]][wallPos[1]].room] == roomSizes[castle[wallPos[0] - 1][wallPos[1]].room]){
				out.println("N");
			} else {
				out.println("E");
			}
		} else {
			out.println("E");
		}
		out.close();
	}
}

class Room{
	boolean visited;
	Room north,south,west,east;
	int connections;
	int room;
	int potential;
	Room(int conn){
		this.connections = conn;
		this.potential = 0;
	}
}