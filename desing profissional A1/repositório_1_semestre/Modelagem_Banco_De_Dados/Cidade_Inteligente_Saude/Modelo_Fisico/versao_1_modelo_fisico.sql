create schema saude;

CREATE TABLE saude.endereco (
    id_endereco SERIAL PRIMARY KEY,
    cep VARCHAR(9) NOT NULL,
    rua VARCHAR(100) NOT NULL,
    numero VARCHAR(10),
    cidade VARCHAR(50),
    estado VARCHAR(2)
);

create table saude.cidadao(
	id_cidadao serial primary key,
	id_endereco INT,
	nome varchar(70),
	telefone int,
	cpf int,
	data_nascimento date,
	sexo varchar(30),
	foreign key (id_endereco) REFERENCES saude.endereco(id_endereco)
);

CREATE TABLE saude.ambulancia (
    id_ambulancia SERIAL PRIMARY KEY,
    placa VARCHAR(10) UNIQUE NOT NULL,
    modelo VARCHAR(50)
);

CREATE TABLE saude.cidadao_chama_ambulancia (
    id_cidadao INT ,
    id_ambulancia INT,
    PRIMARY KEY (id_cidadao, id_ambulancia),
	foreign key (id_cidadao) REFERENCES saude.cidadao(id_cidadao),
	foreign key (id_ambulancia) REFERENCES saude.ambulancia(id_ambulancia)
);

CREATE TABLE saude.unidade_saude (
    id_unidade SERIAL PRIMARY KEY,
    endereco_unidade VARCHAR(100),
    telefone VARCHAR(20),
    nome VARCHAR(100)
);

CREATE TABLE saude.comparece (
    id_cidadao INT ,
    id_unidade INT ,
    PRIMARY KEY (id_cidadao, id_unidade),
	foreign key (id_cidadao) REFERENCES saude.cidadao(id_cidadao),
	foreign key (id_unidade) references saude.unidade_saude(id_unidade)
);

CREATE TABLE saude.transporta (
    id_unidade INT ,
    id_ambulancia INT ,
    PRIMARY KEY (id_unidade, id_ambulancia),

	foreign key (id_unidade) REFERENCES saude.unidade_saude(id_unidade),
	foreign key (id_ambulancia) REFERENCES saude.ambulancia(id_ambulancia)
);

CREATE TABLE saude.triagem (
    codigo SERIAL PRIMARY KEY,
    nome VARCHAR(50)
);

CREATE TABLE saude.realiza (
    id_unidade INT,
    codigo INT,
    PRIMARY KEY (id_unidade, codigo),

	foreign key (id_unidade) REFERENCES saude.unidade_saude(id_unidade),
	foreign key (codigo) REFERENCES saude.triagem(codigo)
);

CREATE TABLE saude.classificacao_us (
    cod_unidade SERIAL PRIMARY KEY,
    codigo_triagem INT,
    nome VARCHAR(50),

	foreign key (codigo_triagem) REFERENCES saude.triagem(codigo)
);

CREATE TABLE saude.atendimento (
    id_atendimento SERIAL PRIMARY KEY,
    cod_unidade INT,
    diagnostico TEXT,
    data_hora TIMESTAMP,

	foreign key (cod_unidade) REFERENCES saude.classificacao_us(cod_unidade)
);

CREATE TABLE saude.profissional_saude (
    id_profissional SERIAL PRIMARY KEY,
    nome VARCHAR(100),
    especialidade VARCHAR(50),
    crm VARCHAR(20)
);

CREATE TABLE saude.atendimento_profissional (
    id_atendimento INT,
    id_profissional INT,
    PRIMARY KEY (id_atendimento, id_profissional),

	foreign key (id_atendimento) REFERENCES saude.atendimento(id_atendimento),
	foreign key (id_profissional) REFERENCES saude.profissional_saude(id_profissional)
);

insert into saude.unidade_saude (endereco_unidade, telefone, nome)
values ( 'Q 12 CJ B LT 38', 6120171200, 'Hospital Regional de Sobradinho' ), ( 'Endereço: DF 420 Km 03', 34856139, 'UPA de Sobradinho' )

update saude.unidade_saude
set nome = 'Hospital de sobradinho'
where nome = 'Hospital Regional de Sobradinho'

delete from saude.unidade_saude
where nome = 'UPA de Sobradinho'

select * from saude.cidadao;
select * from saude.atendimento;
select * from saude.atendimento_profissional;
select * from saude.unidade_saude;