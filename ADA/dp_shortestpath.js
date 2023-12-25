
// JavaScript program to find shortest distance
// in a multistage graph.

let N = 8;
let INF = Number.MAX_VALUE;

// Returns shortest distance from 0 to
	// N-1.
function shortestDist(graph)
{
	// dist[i] is going to store shortest
		// distance from node i to node N-1.
		let dist = new Array(N);

        console.log("1) Inisialisasi Array");
        for (const element of dist) {
            console.log(element);
        }
        console.log("-----------\n");
		
		dist[N - 1] = 0;
		
		console.log("2) Set target node path as 0");
        for (const element of dist) {
            console.log(element);
        }
        console.log("-----------\n");

		// Calculating shortest path for
		// rest of the nodes
		for (let i = N - 2; i >= 0; i--)
		{

			// Initialize distance from i to
			// destination (N-1)
			dist[i] = INF;
			
			console.log("3) calculate in node " + i);
            for (const element of dist) {
                console.log(element);
            }
            console.log("-----------\n");

			// Check all nodes of next stages
			// to find shortest distance from
			// i to N-1.
			for (let j = i; j < N; j++)
			{
				// Reject if no edge exists
				if (graph[i][j] == INF)
				{
					continue;
				}

				// We apply recursive equation to
				// distance to target through j.
				// and compare with minimum distance
				// so far.
				dist[i] = Math.min(dist[i], graph[i][j]
						+ dist[j]);
			}
			
			console.log("4) calculate in node " + i);
            for (const element of dist) {
                console.log(element);
            }
            console.log("-----------\n");
		}
		
		console.log("5) final ");
        for (const element of dist) {
            console.log(element);
        }
        console.log("-----------\n");
		return dist[0];
}

let graph = [[INF, 1, 2, 5, INF, INF, INF, INF],
		[INF, INF, INF, INF, 4, 11, INF, INF],
		[INF, INF, INF, INF, 9, 5, 16, INF],
		[INF, INF, INF, INF, INF, INF, 2, INF],
		[INF, INF, INF, INF, INF, INF, INF, 18],
		[INF, INF, INF, INF, INF, INF, INF, 13],
		[INF, INF, INF, INF, INF, INF, INF, 2]];
shortestDist(graph);

