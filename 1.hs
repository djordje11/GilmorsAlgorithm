data Term = Var String
           | Fn String [Term]


term_to_string :: Term -> String
term_to_string (Var s) = s
term_to_string (Fn s xs) = s ++ "(" ++ tail (foldl (\x y ->  x ++ "," ++ term_to_string y) "" xs) ++ ")"



itlist f list x = foldr f x list
allpairs f xs ys = [f x| x <- xs] <*> ys

groundterms cntms funcs n 
           | n == 0 = cntms
           | otherwise = itlist (\(f, m) l -> map (\args -> Fn f args) (groundtuples cntms funcs (n-1) m ) ++ l) funcs []

groundtuples cntms funcs n m
           | m == 0 = if n == 0 then [[]] else []
           | otherwise = itlist (\ k l -> allpairs (:) (groundterms cntms funcs k) (groundtuples cntms funcs (n-k) (m-1)) ++ l) [0..n] []