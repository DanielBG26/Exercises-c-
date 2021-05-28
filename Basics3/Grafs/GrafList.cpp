#include "GrafList.h"
#include <iomanip>

struct ComparaPair
{
	ComparaPair(int val) : m_valor(val) {}
	bool operator()(const std::pair<int, int>& elem) const 
	{
		return m_valor == elem.first;
	}
	bool operator==(const std::pair<int, int>& elem) const
	{
		return m_valor == elem.first;
	}
private:
	int m_valor;
};

Graf::Graf(bool dirigit)
{
	m_numNodes = 0;
	m_numArestes = 0;
	m_dirigit = dirigit;
}

Graf::Graf(vector<string>& nodes, vector<vector<int>>& parNodes, bool dirigit)
{
	m_numNodes = nodes.size();
	m_nodes.resize(m_numNodes);
	m_veins.resize(m_numNodes);
	m_dirigit = dirigit;
	m_numArestes = parNodes.size();

	for (int i = 1; i <= m_numNodes; i++)
	{
		m_nodes[i-1] = nodes[i-1];		
	}
	for (int j = 1; j <= parNodes.size(); j++)
	{
		if ((parNodes[j-1][0] < m_numNodes) && (parNodes[j-1][1] < m_numNodes) && 
			(parNodes[j-1][0] >= 0) && (parNodes[j-1][1]>= 0))
		{
			m_veins[parNodes[j-1][0]].emplace_back(pair<int,int>(parNodes[j-1][1],1));
			if (!dirigit)
			{
				m_veins[parNodes[j-1][1]].emplace_back(pair<int, int>(parNodes[j-1][0], 1));
			}
		}			
	}
}
Graf::Graf(vector<string>& nodes, vector<vector<int>>& parNodes, vector<int>& pesos,bool dirigit)
{
	m_numNodes = nodes.size();
	m_nodes.resize(m_numNodes);
	m_veins.resize(m_numNodes);
	m_dirigit = dirigit;
	m_numArestes = parNodes.size();

	for (int i = 1; i <= m_numNodes; i++)
	{
		m_nodes[i-1] = nodes[i-1];
	}
	for (int j = 1; j <= parNodes.size(); j++)
	{
		if ((parNodes[j-1][0] < m_numNodes) && (parNodes[j-1][1] < m_numNodes) &&
			(parNodes[j-1][0] >= 0) && (parNodes[j-1][1] >= 0))
		{
			m_veins[parNodes[j-1][0]].emplace_back(pair<int, int>(parNodes[j-1][1], pesos[j-1]));
			if (!dirigit)
			{
				m_veins[parNodes[j-1][1]].emplace_back(pair<int, int>(parNodes[j-1][0], pesos[j-1]));
			}
		}
	}
}
Graf::~Graf()
{
}

void Graf::inserirAresta(int posNode1, int posNode2)
{
	if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes) && (posNode1 >= 0) && (posNode2 >= 0))
	{
		m_veins[posNode1].emplace_back(pair<int,int>(posNode2,1));
		if (!m_dirigit)
		{
			m_veins[posNode2].emplace_back(pair<int, int>(posNode1, 1));
		}
		m_numArestes++;
	}	
}

void Graf::inserirAresta(int posNode1, int posNode2, int pes)
{
	if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes)&& (posNode1 >=0) && (posNode2 >= 0))
	{
		m_veins[posNode1].emplace_back(pair<int, int>(posNode2, pes));
		if (!m_dirigit)
		{
			m_veins[posNode2].emplace_back(pair<int, int>(posNode1, pes));
		}
		m_numArestes++;
	}
}


void Graf::eliminarAresta(int posNode1, int posNode2)
{
	list<pair<int, int>>::iterator itAre = find_if(m_veins[posNode1].begin(), m_veins[posNode1].end(),ComparaPair(posNode2));
	if (itAre != m_veins[posNode1].end())
	{
		m_veins[posNode1].erase(itAre);
		m_numArestes--;
	}
	if (!m_dirigit)
	{
		itAre = find_if(m_veins[posNode2].begin(), m_veins[posNode2].end(), ComparaPair(posNode1));
		if (itAre != m_veins[posNode2].end())
		{
			m_veins[posNode2].erase(itAre);
		}		
	}
}

void Graf::afegirNode(string node)
{
	m_nodes.push_back(node);
	m_numNodes++;	
	m_veins.resize(m_numNodes);
}


void Graf::eliminarNode(string node)
{
	//busquem la posici� del node a esborrar
	vector<string>::iterator it;

	it = find(m_nodes.begin(), m_nodes.end(), node);
	//mirem si node existeix
	if (it != m_nodes.end())
	{
		//Obtenim index del node
		int nodeIndex = it - m_nodes.begin();
		
		// eliminem el node del vector de nodes
		m_nodes.erase(it);
		//Eliminem arestes desde el node
		m_veins.erase(m_veins.begin()+ nodeIndex);
		//Eliminem arestes cap al node
	
		for (int i = 1; i <= m_veins.size(); i++)
		{//eliminem cada aresta sense ponderar
			m_veins[i-1].remove_if(ComparaPair(nodeIndex));
		}
		m_numNodes--;
	}	
}

vector<vector<string>> Graf::cicles()
{
	vector<vector<string>> parades_cicles;
	for (int first = 0; first < m_numNodes; first++) {
		for (list<pair<int, int>>::iterator it = m_veins[first].begin(); it != m_veins[first].end();it++) {
			for (list<pair<int, int>>::iterator it2 = m_veins[(*it).first].begin(); it2 != m_veins[(*it).first].end(); it2++) {
				for (list<pair<int, int>>::iterator it3 = m_veins[(*it2).first].begin(); it3 != m_veins[(*it2).first].end(); it3++) {
					bool insert=1;
					for (int i = 1; i <= parades_cicles.size(); i++) {
						if (parades_cicles[i-1][0] == m_nodes[first] && parades_cicles[i-1][1] == m_nodes[(*it).first] && parades_cicles[i-1][2] == m_nodes[(*it2).first] ||
							parades_cicles[i-1][0] == m_nodes[first] && parades_cicles[i-1][2] == m_nodes[(*it).first] && parades_cicles[i-1][1] == m_nodes[(*it2).first] ||
							parades_cicles[i-1][1] == m_nodes[first] && parades_cicles[i-1][2] == m_nodes[(*it).first] && parades_cicles[i-1][0] == m_nodes[(*it2).first] ||
							parades_cicles[i-1][1] == m_nodes[first] && parades_cicles[i-1][0] == m_nodes[(*it).first] && parades_cicles[i-1][2] == m_nodes[(*it2).first] ||
							parades_cicles[i-1][2] == m_nodes[first] && parades_cicles[i-1][1] == m_nodes[(*it).first] && parades_cicles[i-1][0] == m_nodes[(*it2).first] ||
							parades_cicles[i-1][2] == m_nodes[first] && parades_cicles[i-1][0] == m_nodes[(*it).first] && parades_cicles[i-1][1] == m_nodes[(*it2).first]) {
							insert = 0;
						}
					}
					if ((*it3).first == first && insert) {
						vector<string> v;
						v.push_back(m_nodes[first]);
						v.push_back(m_nodes[(*it).first]);
						v.push_back(m_nodes[(*it2).first]);
						parades_cicles.push_back(v);
					}
				}
			}
		}
	}
	return parades_cicles;
}

int Graf::grauOutNode(string node)
{
	int pos;
	for (int i = 1; i <= m_numNodes;i++) {
		if (m_nodes[i-1] == node) {
			pos = i-1;
		}
	}
	return m_veins[pos].size();
}

int Graf::grauInNode(string node)
{
	int pos,graus=0;
	for (int i = 1; i <= m_numNodes; i++) {
		if (m_nodes[i-1] == node) {
			pos = i-1;
		}
	}
	for (int i = 1; i <= m_numNodes; i++) {
		for (list<pair<int, int>>::iterator it = m_veins[i-1].begin(); it != m_veins[i-1].end(); it++) {
			if ((*it).first==pos) {
				graus++;
			}
		}
	}
	return graus;
}


void Graf::camins(string node1, string node2, vector<list<string>>& camins)
{

}


void Graf::mostra()
{
	// imprimim el nom dels v�rtexs
	cout << "Graf: NUMNODES: " << m_numNodes << " ; NUMARESTES: " << m_numArestes << ":" << endl;
	cout << "=====NODES=====" << endl;
	for (int i = 1; i <= m_numNodes; i++)
	{
		int espai = 20;
		if ((i-1) == 0) espai--;
		for (int dig = i-1; dig > 0; dig /= 10)
		{
			espai -= 1;
		}
		cout << i-1 << ":" << setw(espai) << m_nodes[i-1] << " ";
		for (list<pair<int,int>>::iterator it = m_veins[i-1].begin(); it != m_veins[i-1].end(); it++)
		{
			cout << "-----> ( " << m_nodes[(*it).first] <<"," << (*it).second << " )  ";			
		}
		cout << endl;
	}	
}

