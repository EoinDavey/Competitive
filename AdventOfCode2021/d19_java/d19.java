import java.util.*;

public class d19 {
    HashMap<Point, Point> invMemo = new HashMap<Point, Point>();
    public static void main(String[] args) {
        d19 d = new d19();
        d.runProg();
    }

    ArrayList<String> readLines() {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> arr = new ArrayList<String>();
        boolean stop = false;
        while(!stop) {
            try {
                String s = sc.nextLine();
                arr.add(s);
            } catch(NoSuchElementException e) {
                stop=true;
            }
        }
        return arr;
    }

    ArrayList<ArrayList<Point>> scanners(ArrayList<String> lines) {
        var scanners = new ArrayList<ArrayList<Point>>();
        int i = 0;
        while(i < lines.size()) {
            i++;
            var beacons = new ArrayList<Point>();
            while(i < lines.size() && lines.get(i) != "") {
                var vls = lines.get(i).split(",");
                var pt = new Point(Integer.parseInt(vls[0]), Integer.parseInt(vls[1]), Integer.parseInt(vls[2]));
                beacons.add(pt);
                i++;
            }
            scanners.add(beacons);
            i++;
        }
        return scanners;
    }

    ArrayList<Point> getRots() {
        var s = new HashSet<Point>();
        s.add(new Point(1, 2, 3));
        var stop = false;
        while(!stop) {
            stop = true;
            var l = s.size();
            var elts = new ArrayList<Point>(s);
            for(Point elt : elts) {
                var s1 = new Point(elt.getY(), -elt.getX(), elt.getZ());
                var s2 = new Point(elt.getZ(), elt.getY(), -elt.getX());
                var s3 = new Point(elt.getX(), elt.getZ(), -elt.getY());
                s.addAll(Arrays.asList(s1, s2, s3));
            }
            if(s.size() > l)
                stop = false;
        }
        return new ArrayList<Point>(s);
    }

    Point appRot(Point pt, Point rot) {
        return new Point(
                ((int) Math.signum(rot.getX())) * pt.get(Math.abs(rot.getX()) - 1),
                ((int) Math.signum(rot.getY())) * pt.get(Math.abs(rot.getY()) - 1),
                ((int) Math.signum(rot.getZ())) * pt.get(Math.abs(rot.getZ()) - 1));
    }

    Point inverseRot(Point rot, ArrayList<Point> rots) {
        var mem = invMemo.get(rot);
        if(mem != null)
            return mem;
        for(Point r : rots) {
            if(appRot(rot, r).equals(new Point(1,2,3))) {
                invMemo.put(rot, r);
                return r;
            }
        }
        return rot;
    }

    ArrayList<Point> rotList(ArrayList<Point> pts, Point rot) {
        var out = new ArrayList<Point>();
        for(var pt : pts)
            out.add(appRot(pt, rot));
        return out;
    }

    Point evalMatch(Point da, Point db, ArrayList<Point> ds1, ArrayList<Point> ds2) {
        var b = da.sub(db);
        var sa = new HashSet<Point>(ds1);
        var sb = new HashSet<Point>();
        for(var d : ds2)
            sb.add(b.add(d));
        var icnt = 0;
        for(var k : sa){
            if(sb.contains(k))
                icnt++;
        }
        if(icnt >= 12)
            return b;
        return null;
    }

    MatchResult tryMatch(ArrayList<Point> ds1, ArrayList<Point> ds2, ArrayList<Point> rots) {
        for(var r : rots) {
            var ds2Rot = rotList(ds2, r);
            for(var da : ds1) {
                for(var db : ds2Rot) {
                    var bpos = evalMatch(da, db, ds1, ds2Rot);
                    if(bpos != null) {
                        return new MatchResult(bpos, r);
                    }
                }
            }
        }
        return null;
    }

    void runProg() {
        var lines = readLines();
        var scanners = scanners(lines);
        var rots = getRots();
        var graph = new HashMap<Integer, ArrayList<GraphEdge>>();

        for(int i = 0; i < scanners.size(); i++) {
            if(!graph.containsKey(i))
                graph.put(i, new ArrayList<GraphEdge>());
            for(int j = i+1; j < scanners.size(); j++) {
                if(!graph.containsKey(j))
                    graph.put(j, new ArrayList<GraphEdge>());

                var mtch = tryMatch(scanners.get(i), scanners.get(j), rots);
                if(mtch == null)
                    continue;
                var bPosDiff = mtch.posDiff;
                var rot = mtch.rot;
                var ir = inverseRot(rot, rots);
                var invBPosDiff = new Point(0, 0, 0).sub(appRot(bPosDiff, ir));

                graph.get(i).add(new GraphEdge(j, bPosDiff, rot));
                graph.get(j).add(new GraphEdge(i, invBPosDiff, ir));
            }
        }

        var q = new ArrayList<QueueEntry>();
        q.add(new QueueEntry(0, new Point(1, 2, 3)));
        var vis = new HashSet<Integer>();
        var posMap = new HashMap<Integer, Point>();
        posMap.put(0, new Point(0, 0, 0));

        var allBeacons = new HashSet<Point>();

        while(q.size() > 0) {
            QueueEntry qe = q.remove(q.size() - 1);
            var id = qe.scannerID;
            vis.add(id);
            var rotA = qe.rot;
            var p = posMap.get(id);
            for(var d : rotList(scanners.get(id), rotA))
                allBeacons.add(p.add(d));

            for(var ge : graph.get(id)) {
                if(vis.contains(ge.scannerID))
                    continue;
                var relPos = appRot(ge.posDiff, rotA);
                var absPos = p.add(relPos);
                posMap.put(ge.scannerID, absPos);
                q.add(new QueueEntry(ge.scannerID, appRot(ge.rot, rotA)));
            }
        }
        System.out.println("Part 1: " + allBeacons.size());

        int mxDist = 0;
        for(int i = 0; i < scanners.size(); i++) {
            var a = posMap.get(i);
            for(int j = i+1; j < scanners.size(); j++) {
                var ba = a.sub(posMap.get(j));
                int d = Math.abs(ba.getX()) + Math.abs(ba.getY()) + Math.abs(ba.getZ());
                mxDist = d > mxDist ? d : mxDist;
            }
        }

        System.out.println("Part 2: " + mxDist);
    }
}

class Point {
    private int x, y, z;
    Point(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    @Override
    public int hashCode() { return this.x * this.y * this.z; }
    @Override
    public boolean equals(Object o) {
        if(this == o)
            return true;
        if(o == null || o.getClass() != this.getClass())
            return false;
        Point p = (Point) o;
        return this.x == p.x && this.y == p.y && this.z == p.z;
    }
    @Override
    public String toString() { return "(" + this.x + "," + this.y + "," + this.z + ")"; }

    public int getX(){ return this.x; }
    public int getY(){ return this.y; }
    public int getZ(){ return this.z; }

    public int get(int idx) {
        if(idx == 0)
            return this.x;
        if(idx == 1)
            return this.y;
        return this.z;
    }

    public Point add(Point r) { return new Point(this.x + r.x, this.y + r.y, this.z + r.z); }
    public Point sub(Point r) { return new Point(this.x - r.x, this.y - r.y, this.z - r.z); }
}

class MatchResult{
    public Point posDiff;
    public Point rot;
    MatchResult(Point p, Point r) {
        this.posDiff = p;
        this.rot = r;
    }
    @Override
    public String toString() { return "(" + this.posDiff + "," + this.rot + ")"; }
}

class GraphEdge{
    public int scannerID;
    public Point posDiff;
    public Point rot;
    GraphEdge(int id, Point p, Point r) {
        this.scannerID = id;
        this.posDiff = p;
        this.rot = r;
    }
    @Override
    public String toString() { return "(" + this.scannerID + "," + this.posDiff + "," + this.rot + ")"; }
}

class QueueEntry{
    public int scannerID;
    public Point rot;
    QueueEntry(int id, Point r) {
        this.scannerID = id;
        this.rot = r;
    }
    @Override
    public String toString() { return "(" + this.scannerID + "," + this.rot + ")"; }
}
