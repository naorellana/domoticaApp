<%@page contentType="text/html" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1.0"/>
    <title>Welcome</title>

    <!-- CSS  -->
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <link href="/css/materialize.css" type="text/css" rel="stylesheet" media="screen,projection"/>
    <link href="/css/style.css" type="text/css" rel="stylesheet" media="screen,projection"/>
</head>
<body>
    <header>
        <nav class="black lighten-1" role="navigation">
            <div class="nav-wrapper container"><a id="logo-container" href="/" class="brand-logo">App</a>
                <ul class="right hide-on-med-and-down">
                    <li><a href="home">CRUD</a></li>
                    <li><a href="home">Usuarios</a></li>
                </ul>

                <ul id="nav-mobile" class="side-nav">                 
                    <li><a href="home">CRUD</a></li>
                    <li><a href="home">Usuarios</a></li>
                </ul>
                <a href="#" data-activates="nav-mobile" class="button-collapse"><i class="material-icons">menu</i></a>
            </div>
        </nav>
    </header>
