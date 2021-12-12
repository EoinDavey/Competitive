import 'dart:io';

List<List<String>> readInp() {
    List<List<String>> out = [];
    while(true) {
        var line = stdin.readLineSync();
        if(line == null)
            break;
        out.add(line.split("-"));
    }
    return out;
}

typedef Graph = Map<String, List<String>>;
void push(Graph mp, String k, String v) {
    mp.update(k, (cur) { return cur + [v]; }, ifAbsent: (){return [v];});
}

Graph buildGraph(List<List<String>> inp) {
    Graph mp = Map();
    for(final line in inp) {
        var a = line[0];
        var b = line[1];
        push(mp, a, b);
        push(mp, b, a);
    }
    return mp;
}

bool isSmall(String wrd) {
    for(int i = 0; i < wrd.length; i++) {
        var ch = wrd[i];
        if(ch.compareTo('a') < 0 || ch.compareTo('z') > 0)
            return false;
    }
    return true;
}

int explore(Graph g, String c, Set<String> vis, bool usedDV) {
    if(c == "end")
        return 1;
    var sm = 0;
    for(final n in g[c]!) {
        if(!(isSmall(n) && vis.contains(n))) {
            if(isSmall(n))
                vis.add(n);
            sm += explore(g, n, vis, usedDV);
            if(isSmall(n))
                vis.remove(n);
        }
        if(isSmall(n) && vis.contains(n) && !usedDV && n != "start")
            sm += explore(g, n, vis, true);
    }
    return sm;
}

void partA(Graph g) {
    print(explore(g, "start", Set.from(["start"]), true));
}

void partB(Graph g) {
    print(explore(g, "start", Set.from(["start"]), false));
}

void main() {
    var inp = readInp();
    var g = buildGraph(inp);
    partA(g);
    partB(g);
}
