function [classified_input] = classificatore( input_image )
    
    %%  Analisi spettrale dell'immagine
    %   Output: mappa 3d delle variazioni, vettore con le varianze totali per
    %   livello, bordi dei K gruppi dopo il partizionamento intelligente
    
    [fis, fisa, redMSpectralImage] = spectral_analysis(input_image);
    
    %% Costruzione del classificatore SVM
    
    classificatoreSVM = build_svm_classifier(redMSpectralImage, fis, fisa);
    
    % riduzione della dimensionalità dei dati
    classified_input = svmclassify(reduced_input,classificatoreSVM);
end
