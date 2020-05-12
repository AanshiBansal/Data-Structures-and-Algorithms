//Prims Algorithm
//Number of Vertex 
//Vertex B[i][0] and B[i][1] are connected using a bridge of cost B[i][2]
typedef pair<int, int> iPair; 
int primsMST(int A, vector<vector<int> > &B) {
    //making adjuscancy list using pair
    vector<vector<iPair> >adj(A+1);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back({B[i][1],B[i][2]});
        adj[B[i][1]].push_back({B[i][0],B[i][2]});
    }
    long long ans=0;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    int src = 1;
    vector<int> key(A+1, INT_MAX); 
    vector<bool> inMST(A+1, false); 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
    while (!pq.empty()) 
    {
        int u = pq.top().second;
        int value=pq.top().first;
        pq.pop(); 
        if(inMST[u]==true)
        continue;
        inMST[u] = true;  // Include vertex in MST 
        ans+=value;
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
            if (inMST[v] == false && key[v] > weight) 
            { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v));
            } 
        } 
    } 
    return ans;
}


