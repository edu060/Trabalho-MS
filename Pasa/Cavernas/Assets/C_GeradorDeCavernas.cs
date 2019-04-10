using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class C_GeradorDeCavernas : MonoBehaviour
{
    public int Mapa_X;
    public int Mapa_Y;

    public string seed;
    public bool usar_seed_aleatoria;

    [Range(0, 100)]
    public int Porcentagem_Aleatoria;

    public bool caverna = false;

    int[,] mapa;

    void Start()
    {
        Gerar_Caverna();
    }

    void Update()
    {
        if(Input.GetMouseButtonDown(0))
        {
            Gerar_Caverna();
        }
        if (Input.GetMouseButtonDown(1))
        {
            Suavisar_Mapa();
        }
    }

    void Gerar_Caverna()
    {
        mapa = new int[Mapa_X, Mapa_Y];
        Preenchimento_De_Mapa();

        for (int i = 0; i < 10; i++)
        {
            Suavisar_Mapa();
        }
    }

    void Preenchimento_De_Mapa()
    {
        if (usar_seed_aleatoria)
        {
            seed = Time.time.ToString();
        }

        System.Random Gerado_De_Numero_Procedural = new System.Random(seed.GetHashCode());

        for (int x = 0; x < Mapa_X; x++)
        {
            for (int y = 0; y < Mapa_Y; y++)
            {
                if (x == 0 || x == Mapa_X - 1 || y == 0 || y == Mapa_Y - 1)
                {
                    mapa[x, y] = 1;
                }
                else
                {
                    mapa[x, y] = (Gerado_De_Numero_Procedural.Next(0, 100) < Porcentagem_Aleatoria) ? 1 : 0;
                }
            }
        }
    }

    void Suavisar_Mapa()
    {
        for (int x = 0; x < Mapa_X; x++)
        {
            for (int y = 0; y < Mapa_Y; y++)
            {
                //Parede_Viz_Tile = PVT
                int PVT = Num_Objs_Contato(x,y);

                if(caverna)
                {
                    if (PVT > 4)
                    {
                        //Preto
                        mapa[x, y] = 1;
                    }
                    if(PVT < 4)
                    {
                        //Cinza
                        mapa[x, y] = 0;
                    }
                }
                else
                {
                    if (mapa[x, y] == 0)
                    {
                        if (PVT < 2)
                        {
                            mapa[x, y] = 0;
                        }
                        else if (PVT == 2 || PVT == 3)
                        {
                            mapa[x, y] = 1;
                        }
                        else if (PVT > 3)
                        {
                            mapa[x, y] = 0;
                        }
                    }
                    else
                    {
                        if (PVT == 3)
                        {
                            mapa[x, y] = 1;
                        }
                    }
                }  
            }
        }
    }

    int Num_Objs_Contato(int MapX, int MapY)
    {
        int Parede_Cont = 0;

        for (int X = MapX - 1; X <= MapX + 1; X++)
        {
            for (int Y = MapY - 1; Y <= MapY + 1; Y++)
            {
                if (X >= 0 && X < Mapa_X && Y >= 0 && Y < Mapa_Y)
                {
                    if (X != MapX || Y != MapY)
                    {
                        Parede_Cont += mapa[X, Y];
                    }
                }
                else
                {
                    Parede_Cont++;
                }
            }
        }

        return Parede_Cont;
    }

    void OnDrawGizmos()
    {
        if (mapa != null)
        {
            for (int x = 0; x < Mapa_X; x++)
            {
                for (int y = 0; y < Mapa_Y; y++)
                {
                    Gizmos.color = (mapa[x, y] == 1) ? Color.black : Color.white;
                    Vector3 pos = new Vector3(-Mapa_X / 2 + x + 0.5f, 0, -Mapa_Y / 2 + y + 0.5f);
                    Gizmos.DrawCube(pos, Vector3.one);
                }
            }
        }
    }
}
