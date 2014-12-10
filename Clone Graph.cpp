class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *ret;
        if(node == NULL){
            return NULL;
        }
        
        map<int, UndirectedGraphNode *> mapNodes;
        queue<UndirectedGraphNode *> q;
        
        
        q.push(node);
        
        
        while (!q.empty()) {
            UndirectedGraphNode *tmp = q.front();
            q.pop();
            
            if(mapNodes.find(tmp->label) == mapNodes.end()){
                UndirectedGraphNode *new_node = new UndirectedGraphNode(tmp->label);
                mapNodes.insert(pair<int, UndirectedGraphNode*>(new_node->label,new_node));
                for(int i = 0 ; i < tmp->neighbors.size();i++){
                    q.push(tmp->neighbors[i]);
                }
            }
        }
        
        
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *tmp = q.front();
            q.pop();
            UndirectedGraphNode *existingnode = mapNodes[tmp->label];
            if (existingnode->neighbors.empty() && !tmp->neighbors.empty()) {
                for (int i = 0; i < tmp->neighbors.size(); i++) {
                    existingnode->neighbors.push_back(mapNodes[tmp->neighbors[i]->label]);
                    q.push(tmp->neighbors[i]);
                }
            }
        }
        
        return mapNodes[node->label];
    }
};