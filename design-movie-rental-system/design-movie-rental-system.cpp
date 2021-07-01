class MovieRentingSystem {
public:
    
    unordered_map<int,set<pair<int,int>>>unrented_movies;
    unordered_map<int,unordered_map<int,int>>getPrice;
    set<vector<int>>rented_movies;
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) 
    {
        for(int i=0; i<entries.size(); i++)
        {
            int shopId=entries[i][0];
            int movieId=entries[i][1];
            int price=entries[i][2];
            
            unrented_movies[movieId].insert({price,shopId});
            getPrice[movieId][shopId]=price;
        }
        
        // for(auto item: unrented_movies)
        // {
        //     int movieId=item.first;
        //     set<pair<int,int>>st=item.second;
        //     cout<<movieId<<" ---> ";
        //     for(auto [x,y]: st)
        //         cout<<"( "<<x<<" , "<<y<<" ) "<<" ";
        //     cout<<endl;
        // }
        
        
    }
    
    vector<int> search(int movieId) 
    {
        vector<int>shops;
        set<pair<int,int>>st=unrented_movies[movieId];
        for(auto [price,shopId]: st)
        {
            shops.push_back(shopId);
            if(shops.size()==5)
                break;
        }
        return shops;
    }
    
    void rent(int shopId, int movieId) 
    {
        int price=getPrice[movieId][shopId];
        unrented_movies[movieId].erase({price,shopId});
        rented_movies.insert({price,shopId,movieId});
    }
    
    void drop(int shopId, int movieId) 
    {
        int price=getPrice[movieId][shopId];
        rented_movies.erase({price,shopId,movieId});
        unrented_movies[movieId].insert({price,shopId});
    }
    
    vector<vector<int>> report() 
    {
        vector<vector<int>>ans;
        for(auto item: rented_movies)
        {
            int shopId=item[1];
            int movieId=item[2];
            ans.push_back({shopId,movieId});
            if(ans.size()==5)
                break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */