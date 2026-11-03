@@
-        int r = reduction(improving, depth, moveCount);
+        int r = reduction(improving, depth, moveCount);
+
+        // History-informed LMR tuning: strong quiet moves are searched deeper,
+        // while weak quiet moves get an extra reduction. This helps the engine
+        // focus effort on the promising lines without wasting too much time on
+        // obviously poor continuations.
+        if (!capture && !givesCheck)
+        {
+            const int historyBonus = (*contHist[0])[movedPiece][move.to_sq()]
+                                  + (*contHist[1])[movedPiece][move.to_sq()]
+                                  + sharedHistory.pawn_entry(pos)[movedPiece][move.to_sq()];
+
+            if (depth >= 4 && historyBonus > 12000)
+                r -= 512;
+            else if (depth >= 4 && historyBonus < -6000)
+                r += 512;
+        }
 
         // Decrease reduction for PvNodes
         if (PvNode)
             r -= 512;
@@
-        // Decrease/increase reduction for moves with a good/bad history
+        // Decrease/increase reduction for moves with a good/bad history
         r -= ss->statScore * 439 / 4096;
+
+        // Further refine LMR based on the quiet move quality. A strong quiet move
+        // should be searched with a slightly shallower reduction, while a low
+        // quality quiet move should be pruned more aggressively.
+        if (!capture && !givesCheck && depth >= 3)
+        {
+            const int quietHistory = (*contHist[0])[movedPiece][move.to_sq()]
+                                  + (*contHist[1])[movedPiece][move.to_sq()]
+                                  + sharedHistory.pawn_entry(pos)[movedPiece][move.to_sq()];
+
+            if (quietHistory > 9000)
+                r -= 256;
+            else if (quietHistory < -3000)
+                r += 256;
+        }
 
         if (!capture && !is_decisive(alpha))
             r += 3 * std::clamp(alpha - eval, -64, 96);
